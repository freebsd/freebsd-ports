--- chatterino.pro.orig	2020-08-31 13:27:53 UTC
+++ chatterino.pro
@@ -82,7 +82,6 @@ include(lib/settings.pri)
 include(lib/serialize.pri)
 include(lib/winsdk.pri)
 include(lib/rapidjson.pri)
-include(lib/qtkeychain.pri)
 
 exists( $$OUT_PWD/conanbuildinfo.pri ) {
     message("Using conan packages")
@@ -576,7 +575,7 @@ git_commit=$$system(git rev-parse HEAD)
 isEmpty(git_release) {
 git_release=$$system(git describe)
 }
-git_hash = $$str_member($$git_commit, 0, 8)
+git_hash = $$git_commit
 
 # Passing strings as defines requires you to use this weird triple-escape then quotation mark syntax.
 # https://stackoverflow.com/questions/3348711/add-a-define-to-qmake-with-a-value/18343449#18343449
