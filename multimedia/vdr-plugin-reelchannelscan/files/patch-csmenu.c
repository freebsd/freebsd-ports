--- a/csmenu.c
+++ b/csmenu.c
@@ -378,8 +378,12 @@ void cMenuChannelscan::Set()
 
     // avoid C/T-positions for SAT
     // and take Astra as start position
-    if (srcTypes[currentTuner] >= SAT && (source == cSource::FromString("C") || source == cSource::FromString("T"))) {
-        source = cSource::FromString("S19.2E");
+    if (srcTypes[currentTuner] >= SAT && (source == cSource::FromString("C") || source == cSource::FromString("T") || !Sources.Get(source))) {
+        cDiseqc *d = Diseqcs.First();
+        if (Setup.DiSEqC > 0 && d)
+            source = d->Source();
+        else
+            source = cSource::FromString("S19.2E");
     }
 
     Add(new cMenuEditStraItem(tr("Search Mode"), &scanMode, 2, searchTexts));
@@ -1209,7 +1213,7 @@ eOSState cMyMenuEditSrcItem::ProcessKey(
     {
         if (NORMALKEY(Key) == kLeft)    // TODO might want to increase the delta if repeated quickly?
         {
-           if(cSource::IsSat(source->Code()) && !cPluginManager::GetPlugin("mcli")) {
+           if(cSource::IsSat(source->Code()) && !cPluginManager::GetPlugin("mcli") && Setup.DiSEqC > 0) {
                 source = oldSrc;
                 while(!found && source && (source->Code() & cSource::stSat)) {
                     for (cDiseqc *p = Diseqcs.First(); p && !found; p = Diseqcs.Next(p)) {
@@ -1231,7 +1235,7 @@ eOSState cMyMenuEditSrcItem::ProcessKey(
              }
            }
         } else if (NORMALKEY(Key) == kRight) {
-            if (cSource::IsSat(source->Code()) && !cPluginManager::GetPlugin("mcli")) {
+            if (cSource::IsSat(source->Code()) && !cPluginManager::GetPlugin("mcli") && Setup.DiSEqC > 0) {
                source = oldSrc;
                while(!found && source && (source->Code() & cSource::stSat)) {
                    for (cDiseqc *p = Diseqcs.First(); p && !found; p = Diseqcs.Next(p)) {
