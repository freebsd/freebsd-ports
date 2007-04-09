--- src/os/OsSysLogTask.cpp.orig	Sat Apr  7 18:56:44 2007
+++ src/os/OsSysLogTask.cpp	Sat Apr  7 18:58:16 2007
@@ -273,10 +273,10 @@
                processConsoleEnable(FALSE);
                break ;
             case OsSysLogMsg::HEAD:
-               processHeadCommand((int) pSysLogMsg->getData());
+               processHeadCommand((int) ((uintptr_t)pSysLogMsg->getData()));
                break ;
             case OsSysLogMsg::TAIL:
-               processTailCommand((int) pSysLogMsg->getData());
+               processTailCommand((int) ((uintptr_t)pSysLogMsg->getData()));
                break ;
             case OsSysLogMsg::ADD_SOCKET:
                data = (char*) pSysLogMsg->getData();
@@ -298,7 +298,7 @@
                processSetCallback((OsSysLogCallback) pSysLogMsg->getData());
                break ;
             case OsSysLogMsg::SET_FLUSH_PERIOD:
-               processSetFlushPeriod((int) pSysLogMsg->getData()) ;
+               processSetFlushPeriod((int) ((uintptr_t)pSysLogMsg->getData())) ;
                break ;
             case OsSysLogMsg::FLUSH_LOG:
                processFlushLog((OsEvent*) pSysLogMsg->getData());
