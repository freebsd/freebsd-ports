--- src/settings.cpp~	Mon Apr  9 16:55:43 2007
+++ src/settings.cpp	Mon Apr  9 16:55:43 2007
@@ -0,0 +1,113 @@
+/*  dvbcut settings
+    Copyright (c) 2006 Michael Riepe
+ 
+    This program is free software; you can redistribute it and/or modify
+    it under the terms of the GNU General Public License as published by
+    the Free Software Foundation; either version 2 of the License, or
+    (at your option) any later version.
+ 
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+ 
+    You should have received a copy of the GNU General Public License
+    along with this program; if not, write to the Free Software
+    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+*/
+
+#include <string>
+#include <vector>
+
+#include <assert.h>
+
+#include "defines.h"
+#include "settings.h"
+
+dvbcut_settings::dvbcut_settings() {
+  setPath(DVBCUT_QSETTINGS_DOMAIN, DVBCUT_QSETTINGS_PRODUCT);
+  beginGroup("/" DVBCUT_QSETTINGS_DOMAIN "/" DVBCUT_QSETTINGS_PRODUCT);
+  load_settings();
+}
+
+dvbcut_settings::~dvbcut_settings() {
+  save_settings();
+  endGroup();
+}
+
+void
+dvbcut_settings::load_settings() {
+  viewscalefactor = readNumEntry("/viewscalefactor", 1);
+  wheel_increments[WHEEL_INCR_NORMAL] = readNumEntry("/wheel_incr_normal", 25*60);
+  wheel_increments[WHEEL_INCR_SHIFT] = readNumEntry("/wheel_incr_shift", 25);
+  wheel_increments[WHEEL_INCR_CTRL] = readNumEntry("/wheel_incr_ctrl", 1);
+  wheel_increments[WHEEL_INCR_ALT] = readNumEntry("/wheel_incr_alt", 15*25*60);
+  wheel_threshold = readNumEntry("/wheel_threshold", 24);
+  // Note: delta is a multiple of 120 (see Qt documentation)
+  wheel_delta = readNumEntry("/wheel_delta", 120);
+  if (wheel_delta == 0)
+    wheel_delta = 1;	// avoid devide by zero
+  jog_maximum = readNumEntry("/jog_maximum", 180000);
+  jog_threshold = readNumEntry("/jog_threshold", 50);
+  // to increase the "zero frames"-region of the jog-slider
+  jog_offset = readDoubleEntry("/jog_offset", 0.4);
+  // sub-intervals of jog_maximum
+  jog_interval = readNumEntry("/jog_interval", 1);
+  if (jog_interval < 0)
+    jog_interval = 0;
+  lin_interval = readNumEntry("/lin_interval", 3600);
+  if (lin_interval < 0)
+    lin_interval = 0;
+  idxfilter = readEntry("/idxfilter", DVBCUT_DEFAULT_IDXFILTER);
+  prjfilter = readEntry("/prjfilter", DVBCUT_DEFAULT_PRJFILTER);
+  loadfilter = readEntry("/loadfilter", DVBCUT_DEFAULT_LOADFILTER);
+  beginGroup("/recentfiles");
+    recentfiles_max = readNumEntry("/max", 5);
+    recentfiles.clear();
+    for (unsigned int i = 0; i < recentfiles_max; ++i) {
+      QString key = "/" + QString::number(i);
+      QString filename = readEntry(key);
+      if (filename.isEmpty())
+	continue;
+      QString idxfilename = readEntry(key + "-idx", "");
+      recentfiles.push_back(
+	std::pair<std::string,std::string>(filename, idxfilename));
+    }
+  endGroup();	// recentfiles
+}
+
+void
+dvbcut_settings::save_settings() {
+  writeEntry("/viewscalefactor", viewscalefactor);
+  writeEntry("/wheel_incr_normal", wheel_increments[WHEEL_INCR_NORMAL]);
+  writeEntry("/wheel_incr_shift", wheel_increments[WHEEL_INCR_SHIFT]);
+  writeEntry("/wheel_incr_ctrl", wheel_increments[WHEEL_INCR_CTRL]);
+  writeEntry("/wheel_incr_alt", wheel_increments[WHEEL_INCR_ALT]);
+  writeEntry("/wheel_threshold", wheel_threshold);
+  writeEntry("/wheel_delta", wheel_delta);
+  writeEntry("/jog_maximum", jog_maximum);
+  writeEntry("/jog_threshold", jog_threshold);
+  writeEntry("/jog_offset", jog_offset);
+  writeEntry("/jog_interval", jog_interval);
+  writeEntry("/lin_interval", lin_interval);
+  writeEntry("/idxfilter", idxfilter);
+  writeEntry("/prjfilter", prjfilter);
+  writeEntry("/loadfilter", loadfilter);
+  beginGroup("/recentfiles");
+    writeEntry("/max", int(recentfiles_max));
+    for (unsigned int i = 0; i < recentfiles_max; ++i) {
+      QString key = "/" + QString::number(i);
+      if (i < recentfiles.size()) {
+	writeEntry(key, recentfiles[i].first);
+	writeEntry(key + "-idx", recentfiles[i].second);
+      }
+      else {
+	removeEntry(key);
+	removeEntry(key + "-idx");
+      }
+    }
+  endGroup();	// recentfiles
+}
+
+// finally, the global settings
+dvbcut_settings settings;
