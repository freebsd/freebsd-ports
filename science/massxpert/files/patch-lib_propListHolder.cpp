Fixes the build with GCC 6 (in addition to fixing an actual bug).

/wrkdirs/usr/ports/science/massxpert/work/massxpert-3.4.0/lib/propListHolder.cpp: In member function 'bool massXpert::PropListHolder::removeProp(const QString&)':
/wrkdirs/usr/ports/science/massxpert/work/massxpert-3.4.0/lib/propListHolder.cpp:216:2: error: this 'if' clause does not guard... [-Werror=misleading-indentation]
  if(m_propList.at(iter)->name() == name);
  ^~
/wrkdirs/usr/ports/science/massxpert/work/massxpert-3.4.0/lib/propListHolder.cpp:217:2: note: ...this statement, but the latter is misleadingly indented as if it is guarded by the 'if'
  {
--- lib/propListHolder.cpp.orig	2017-07-26 17:06:18 UTC
+++ lib/propListHolder.cpp
@@ -213,7 +213,7 @@ namespace massXpert
   {
     for (int iter = 0; iter < m_propList.size(); ++iter)
       {
-	if(m_propList.at(iter)->name() == name);
+	if(m_propList.at(iter)->name() == name)
 	{
 	  m_propList.removeAt(iter);
 	  
