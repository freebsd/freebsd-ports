--- cec.cpp.orig	2017-04-14 13:57:59.489525000 +0000
+++ cec.cpp	2017-04-14 15:16:14.322425000 +0000
@@ -93,7 +93,7 @@ using namespace CEC;
 #endif
 
 // cec_adapter_descriptor and DetectAdapters were introduced in 2.1.0
-#if CEC_LIB_VERSION_MAJOR >= 2 && CEC_LIB_VERSION_MINOR >= 1
+#if CEC_LIB_VERSION_MAJOR >=3 || CEC_LIB_VERSION_MAJOR >= 2 && CEC_LIB_VERSION_MINOR >= 1
 #define CEC_ADAPTER_TYPE cec_adapter_descriptor
 #define CEC_FIND_ADAPTERS DetectAdapters
 #define HAVE_CEC_ADAPTER_DESCRIPTOR 1
@@ -520,36 +520,34 @@ static PyMethodDef CecMethods[] = {
 libcec_configuration * CEC_config;
 ICECCallbacks * CEC_callbacks; 
 
-int log_cb(void * self, const cec_log_message message) {
+void log_cb(void * self, const cec_log_message* message) {
    debug("got log callback\n");
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
-   int level = message.level;
-   long int time = message.time;
+   int level = message->level;
+   long int time = message->time;
    PyObject * args = Py_BuildValue("(iils)", EVENT_LOG, 
          level,
          time,
-         message.message);
+         message->message);
    trigger_event(EVENT_LOG, args);
    Py_DECREF(args);
    PyGILState_Release(gstate);
-   return 1;
 }
 
-int keypress_cb(void * self, const cec_keypress key) {
+void keypress_cb(void * self, const cec_keypress* key) {
    debug("got keypress callback\n");
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
    PyObject * args = Py_BuildValue("(iBI)", EVENT_KEYPRESS,
-         key.keycode,
-         key.duration);
+         key->keycode,
+         key->duration);
    trigger_event(EVENT_KEYPRESS, args);
    Py_DECREF(args);
    PyGILState_Release(gstate);
-   return 1;
 }
 
-int command_cb(void * self, const cec_command command) {
+void command_cb(void * self, const cec_command* command) {
    debug("got command callback\n");
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
@@ -560,10 +558,9 @@ int command_cb(void * self, const cec_co
    //trigger_event(EVENT_COMMAND, args);
    Py_DECREF(args);
    PyGILState_Release(gstate);
-   return 1;
 }
 
-int config_cb(void * self, const libcec_configuration) {
+void config_cb(void * self, const libcec_configuration*) {
    debug("got config callback\n");
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
@@ -578,10 +575,9 @@ int config_cb(void * self, const libcec_
    //trigger_event(EVENT_CONFIG_CHANGE, args);
    Py_DECREF(args);
    PyGILState_Release(gstate);
-   return 1;
 }
 
-int alert_cb(void * self, const libcec_alert alert, const libcec_parameter p) {
+void alert_cb(void * self, const libcec_alert alert, const libcec_parameter p) {
    debug("got alert callback\n");
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
@@ -595,7 +591,6 @@ int alert_cb(void * self, const libcec_a
    trigger_event(EVENT_ALERT, args);
    Py_DECREF(args);
    PyGILState_Release(gstate);
-   return 1;
 }
 
 int menu_cb(void * self, const cec_menu_state menu) {
@@ -654,13 +649,13 @@ PyMODINIT_FUNC initcec(void) {
 #if CEC_LIB_VERSION_MAJOR > 1 || ( CEC_LIB_VERSION_MAJOR == 1 && CEC_LIB_VERSION_MINOR >= 7 )
    CEC_callbacks->Clear();
 #endif
-   CEC_callbacks->CBCecLogMessage = log_cb;
-   CEC_callbacks->CBCecKeyPress = keypress_cb;
-   CEC_callbacks->CBCecCommand = command_cb;
-   CEC_callbacks->CBCecConfigurationChanged = config_cb;
-   CEC_callbacks->CBCecAlert = alert_cb;
-   CEC_callbacks->CBCecMenuStateChanged = menu_cb;
-   CEC_callbacks->CBCecSourceActivated = activated_cb;
+   CEC_callbacks->logMessage = log_cb;
+   CEC_callbacks->keyPress = keypress_cb;
+   CEC_callbacks->commandReceived = command_cb;
+   CEC_callbacks->configurationChanged = config_cb;
+   CEC_callbacks->alert = alert_cb;
+   CEC_callbacks->menuStateChanged = menu_cb;
+   CEC_callbacks->sourceActivated = activated_cb;
 
    CEC_config->callbacks = CEC_callbacks;
 
