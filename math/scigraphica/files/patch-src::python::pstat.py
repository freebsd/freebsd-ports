--- src/python/pstat.py.orig	Wed Aug 20 18:00:12 2003
+++ src/python/pstat.py	Wed Aug 20 18:00:32 2003
@@ -214,8 +214,8 @@
 	    index = col
 	    column = abut(column,map(lambda x: x[index], listoflists))
     elif type(cnums) == StringType:	      # if an 'x[3:]' type expr.
-	execstring = 'column = map(lambda x: x'+cnums+', listoflists)'
-	exec(execstring)
+	execstring = 'map(lambda x: x'+cnums+', listoflists)'
+	column = eval(execstring)
     else:                                     # else it's just 1 col to get
 	index = cnums
 	column = map(lambda x: x[index], listoflists)
