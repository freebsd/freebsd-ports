--- src/helpers/recordserver.py.orig	2009-05-23 08:51:25.000000000 -0400
+++ src/helpers/recordserver.py	2010-04-09 07:53:38.000000000 -0400
@@ -503,10 +503,11 @@
                 thisprog = progs[proglist[i]]
                 nextprog = progs[proglist[i+1]]
                 if thisprog.stop > nextprog.start:
-                    conflictRating = conflictRating+1
                     if thisprog == prog:
+                        conflictRating = conflictRating+1
                         conflicts.append(nextprog)
                     elif nextprog == prog:
+                        conflictRating = conflictRating+1
                         conflicts.append(thisprog)
             self.removeRecordingFromSchedule(prog, myScheduledRecordings)
             return (conflictRating, conflicts)
