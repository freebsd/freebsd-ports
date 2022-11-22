--- gptcl.cc.orig	2022-11-22 09:31:13 UTC
+++ gptcl.cc
@@ -71,7 +71,7 @@ int GPTDataCL::DoOptions(int argc, char* argv[]) {
    uint64_t low, high, startSector, endSector, sSize, mainTableLBA;
    uint64_t temp; // temporary variable; free to use in any case
    char *device;
-   string cmd, typeGUID, name;
+   string cmd, typeGUID, name, devstr;
    PartType typeHelper;
 
    struct poptOption theOptions[] =
@@ -156,9 +156,11 @@ int GPTDataCL::DoOptions(int argc, char* argv[]) {
 
    // Assume first non-option argument is the device filename....
    device = (char*) poptGetArg(poptCon);
+   if (device != NULL)
+        devstr = device;
    poptResetContext(poptCon);
 
-   if (device != NULL) {
+   if (devstr.empty()) {
       JustLooking(); // reset as necessary
       BeQuiet(); // Tell called functions to be less verbose & interactive
       if (LoadPartitions(devstr)) {
@@ -498,7 +500,7 @@ int GPTDataCL::DoOptions(int argc, char* argv[]) {
          cerr << "Error encountered; not saving changes.\n";
          retval = 4;
       } // if
-   } // if (device != NULL)
+   } // if (devstr empty)
    poptFreeContext(poptCon);
    return retval;
 } // GPTDataCL::DoOptions()
