c++ 4.2 (in base 9.x) has a weakness that emits a bogus error:
/usr/ports/math/qhull/work/qhull-2015.2/src/libqhullcpp/QhullSet.h:330: error: expected `;' before 'i'

Work around that by removing overspecified part of type declaration (can remove after 9.x EOL).

--- src/libqhullcpp/QhullSet.h.orig	2016-01-18 19:45:12 UTC
+++ src/libqhullcpp/QhullSet.h
@@ -327,8 +327,8 @@ template <typename T>
 std::vector<T> QhullSet<T>::
 toStdVector() const
 {
-    QhullSet<T>::const_iterator i= begin();
-    QhullSet<T>::const_iterator e= end();
+    const_iterator i= begin();
+    const_iterator e= end();
     std::vector<T> vs;
     while(i!=e){
         vs.push_back(*i++);
