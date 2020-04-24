--- src/rw-match.c.orig	2020-04-22 21:36:45 UTC
+++ src/rw-match.c
@@ -21,7 +21,7 @@ static void die_malformed(char const* str, char const*
 #define DIE_RANGE() DIE1X(100, "timestamp out of range")
 #define DIE_UNIT_RANGE(x0) DIE2X(100, "value out of range for unit: ", x0)
 
-enum { unset, eq, eqn, div };
+enum { UNSET, EQ, EQN, DIV };
 
 typedef struct {
   unsigned int type;
@@ -42,21 +42,21 @@ static unsigned int max_minute  (void) { return 59; }
 static unsigned int max_second  (void) { return 59; }
 
 static unit units_weekday[]={
-  { unset, 0, -1, 0, max_weekday,  6, 'w' },
-  { unset, 0, -1, 0, max_hour   , 23, 'H' },
-  { unset, 0, -1, 0, max_minute , 59, 'M' },
-  { unset, 0, -1, 0, max_second , 59, 'S' },
-  { unset, 0, -1, 0, NULLP      ,  0,  0  }
+  { UNSET, 0, -1, 0, max_weekday,  6, 'w' },
+  { UNSET, 0, -1, 0, max_hour   , 23, 'H' },
+  { UNSET, 0, -1, 0, max_minute , 59, 'M' },
+  { UNSET, 0, -1, 0, max_second , 59, 'S' },
+  { UNSET, 0, -1, 0, NULLP      ,  0,  0  }
 };
 
 static unit units_monthday[]={
-  { unset, 0, -1, 0, max_year    , -1, 'y' },
-  { unset, 0, -1, 1, max_month   , 12, 'm' },
-  { unset, 0, -1, 1, max_monthday, 31, 'd' },
-  { unset, 0, -1, 0, max_hour    , 23, 'H' },
-  { unset, 0, -1, 0, max_minute  , 59, 'M' },
-  { unset, 0, -1, 0, max_second  , 59, 'S' },
-  { unset, 0, -1, 0, NULLP       ,  0,  0  }
+  { UNSET, 0, -1, 0, max_year    , -1, 'y' },
+  { UNSET, 0, -1, 1, max_month   , 12, 'm' },
+  { UNSET, 0, -1, 1, max_monthday, 31, 'd' },
+  { UNSET, 0, -1, 0, max_hour    , 23, 'H' },
+  { UNSET, 0, -1, 0, max_minute  , 59, 'M' },
+  { UNSET, 0, -1, 0, max_second  , 59, 'S' },
+  { UNSET, 0, -1, 0, NULLP       ,  0,  0  }
 };
 
 static unsigned int max_monthday(void) {
@@ -99,26 +99,26 @@ int main(int argc, char** argv) {
                       "\"y\", \"m\", \"d\", \"w\", \"H\", \"M\", or \"S\"");
       if (*constraint_str==units[i].id) break;
     }
-    if (units[i].type!=unset)
+    if (units[i].type!=UNSET)
       DIE2X(100, "duplicate constraint for unit: ", constraint);
     ++constraint_str;
     switch (*constraint_str) {
-      case '=': units[i].type=eq;  break;
-      case '-': units[i].type=eqn; break;
-      case '/': units[i].type=div; break;
+      case '=': units[i].type=EQ;  break;
+      case '-': units[i].type=EQN; break;
+      case '/': units[i].type=DIV; break;
       default: die_malformed(constraint_str, "\"=\", \"-\", \"/\", or \",\"");
     }
     ++constraint_str;
     len=uint_scan(constraint_str, &units[i].spec);
     if (len==0) die_malformed(constraint_str, "number");
-    if (units[i].spec==0) units[i].type=eq;
-    else if (units[i].type==eqn) units[i].spec--;
+    if (units[i].spec==0) units[i].type=EQ;
+    else if (units[i].type==EQN) units[i].spec--;
     if (units[i].spec>units[i].maxmax) {
-      if (units[i].type!=div || units[i].min>0)
+      if (units[i].type!=DIV || units[i].min>0)
         DIE_UNIT_RANGE(constraint);
-      units[i].type=eq;
+      units[i].type=EQ;
       units[i].spec=0;
-    } else if (units[i].spec<units[i].min && units[i].type==eq)
+    } else if (units[i].spec<units[i].min && units[i].type==EQ)
       DIE_UNIT_RANGE(constraint);
     constraint_str+=len;
   }
@@ -149,22 +149,22 @@ int main(int argc, char** argv) {
     }
   }
 
-  for (i=0; units[i].max!=NULLP && units[i].type==unset; ++i)
-    units[i].type=div, units[i].spec=1;
+  for (i=0; units[i].max!=NULLP && units[i].type==UNSET; ++i)
+    units[i].type=DIV, units[i].spec=1;
   for (; units[i].max!=NULLP; ++i)
-    if (units[i].type==unset)
-      units[i].type=eq, units[i].spec=units[i].min;
+    if (units[i].type==UNSET)
+      units[i].type=EQ, units[i].spec=units[i].min;
 
   for (i=0; units[i].max!=NULLP;) {
     unsigned int const value=(flag_increased? units[i].min: units[i].value);
     unsigned int const spec=units[i].spec;
     unsigned int newval;
-    if (units[i].type==div) {
+    if (units[i].type==DIV) {
       newval=value+(spec-1);
       newval-=newval%spec;
       if (flag_need_increase && newval==value) newval+=spec;
     } else {
-      if (units[i].type==eq) newval=spec;
+      if (units[i].type==EQ) newval=spec;
       else newval=units[i].max()-spec;
       if (newval<value) goto need_increase;
       if (flag_need_increase && newval==value) goto need_increase;
