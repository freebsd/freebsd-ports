Local extensions plus a crash fix, carried as a port patch.

Bug fix (upstreamable): query the days/search endpoint for the authenticated
user instead of a user key hardcoded in the source.  Without it the response
is empty and the tool aborts with "list index out of range".

Local feature: derive each working day's required hours from a configurable
contract value (daily_hours) instead of a hardcoded 8, and shorten a working
day by preholiday_reduction when the next calendar day is a Tempo HOLIDAY.
Tempo is used only as the holiday calendar; the work scheme is not required.

--- autotempo.py.orig
+++ autotempo.py
@@ -25,6 +25,8 @@
     API_TOKEN = config["JIRA"]["API_TOKEN"]
     keywords = config["keyword"]
     EMAIL = config["user"]["email"]
+    DAILY_HOURS = config.get("user", {}).get("daily_hours", 8.0)
+    PREHOLIDAY_REDUCTION = config.get("user", {}).get("preholiday_reduction", 1.0)
 except KeyError as e:
     print(f"Missing configuration key: {e}")
     exit(1)
@@ -36,6 +38,8 @@
 
 [user]
 email = "your-email@example.com"                      # Your email address (used for git inspect)
+daily_hours = 8.0                                     # Contract daily working hours
+preholiday_reduction = 1.0                            # Hours subtracted from a pre-holiday day
 
 # Define keywords for common tasks (optional)
 [keyword.meeting]
@@ -111,25 +115,41 @@
     data = {
         "from": start_date,
         "to": end_date,
-        "userKeys": ["JIRAUSER55710"]
+        "userKeys": [WORKER]
     }
-    
+
     try:
         datetime.datetime.strptime(start_date, "%Y-%m-%d")
         datetime.datetime.strptime(end_date, "%Y-%m-%d")
     except ValueError as e:
         print(f"Invalid date format: {e}")
-        return set()
+        return {}
 
     response = requests.post(url, headers=headers, data=json.dumps(data))
 
-    if response.status_code == 200:
-        days_info = response.json()
-        working_days = {day['date'] for day in days_info[0]['days'] if day['type'] == "WORKING_DAY"}
-        return working_days
-    else:
+    if response.status_code != 200:
         raise FatalError(f"Failed to retrieve working days: {response.status_code} {response.text}", response)
 
+    days_info = response.json()
+    if not days_info:
+        raise FatalError(f"Tempo returned no day data for {WORKER}")
+
+    days = days_info[0]['days']
+    holidays = {d['date'] for d in days if d['type'] == "HOLIDAY"}
+
+    required = {}
+    for d in days:
+        if d['type'] != "WORKING_DAY":
+            continue
+        date = d['date']
+        hours = DAILY_HOURS
+        next_day = (datetime.datetime.strptime(date, "%Y-%m-%d")
+                    + datetime.timedelta(days=1)).strftime("%Y-%m-%d")
+        if next_day in holidays:
+            hours -= PREHOLIDAY_REDUCTION
+        required[date] = round(hours, 2)
+    return required
+
 def get_existing_worklogs_for_date(date):
     url = f"{JIRA_URL}/rest/tempo-timesheets/4/worklogs/search"
     headers = {
@@ -261,6 +281,7 @@
     # Generate template
     template_lines = []
     for day in sorted(working_days):
+        base = working_days[day]
         day_dt = datetime.datetime.strptime(day, "%Y-%m-%d")
         day_of_week_name = day_dt.strftime('%A')
         
@@ -284,14 +305,14 @@
                         print(f"Warning: could not parse hours from automatic worklog: '{worklog_line}'. Skipping for hour calculation.")
         
         if day_lines:
-            remaining_hours = 8.0 - total_auto_hours
+            remaining_hours = base - total_auto_hours
             if remaining_hours > 0:
                 day_lines.append(f"{day} {remaining_hours:.1f} jira-ticket \"comment\"")
             elif remaining_hours < 0:
-                print(f"Warning: total hours for non-overtime automatic worklogs on {day} ({day_of_week_name}) exceeds 8 hours.")
+                print(f"Warning: non-overtime automatic worklogs on {day} ({day_of_week_name}) exceed {base} hours.")
             template_lines.extend(day_lines)
         else:
-            template_lines.append(f"{day} 8.0 jira-ticket \"comment\"")
+            template_lines.append(f"{day} {base} jira-ticket \"comment\"")
 
     # Output template
     template_content = (
@@ -362,8 +383,9 @@
     for date in sorted(all_dates):
         total_hours = daily_hours.get(date, 0)
         if date in working_days:
-            if total_hours != 8:
-                raise ValueError(f"Total non-overtime logged hours for {date} is {total_hours}, which is not equal to 8. Stopping worklog application.")
+            expected = working_days[date]
+            if total_hours != expected:
+                raise ValueError(f"Total non-overtime logged hours for {date} is {total_hours}, expected {expected}. Stopping worklog application.")
             valid_dates.append(date)
         else:
             if total_hours != 0:
@@ -518,7 +540,7 @@
     worklog_lines = []
     for commit in commits:
         commit_hash, date, message = commit.split(" ", 2)
-        worklog_lines.append(f"{date} 8.0 {commit_hash} \"{message}\"")
+        worklog_lines.append(f"{date} {DAILY_HOURS} {commit_hash} \"{message}\"")
 
     # Output worklog
     worklog_content = "\n".join(worklog_lines)
