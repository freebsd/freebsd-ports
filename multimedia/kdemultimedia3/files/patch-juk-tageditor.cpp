Index: juk/tageditor.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/juk/tageditor.cpp,v
retrieving revision 1.44.2.4
retrieving revision 1.44.2.5
diff -u -3 -p -u -r1.44.2.4 -r1.44.2.5
--- juk/tageditor.cpp	14 Apr 2004 22:31:08 -0000	1.44.2.4
+++ juk/tageditor.cpp	14 Jun 2004 11:18:37 -0000	1.44.2.5
@@ -50,7 +50,7 @@ public:
 
     virtual State validate(QString &s, int &) const
     {
-	if(s.find('/' != -1))
+	if(s.find('/') != -1)
 	   return Invalid;
 	return Acceptable;
     }
