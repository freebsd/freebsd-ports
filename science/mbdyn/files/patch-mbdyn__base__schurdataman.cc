Fix to Schur data manager caused by the introduction of the output meter;
only affects MBDyn 1.2.6 when --enable-schur

Index: mbdyn/base/schurdataman.cc
===================================================================
RCS file: /var/cvs/mbdyn/mbdyn/mbdyn-1.0/mbdyn/base/schurdataman.cc,v
retrieving revision 1.40.2.6
retrieving revision 1.40.2.7
diff -u -r1.40.2.6 -r1.40.2.7
--- mbdyn/base/schurdataman.cc	18 Jan 2006 16:29:56 -0000	1.40.2.6
+++ mbdyn/base/schurdataman.cc	8 Feb 2006 20:02:29 -0000	1.40.2.7
@@ -1835,7 +1835,7 @@
 	DEBUGCOUT("Entering SchurDataManager::Output()" << std::endl);
 
 	/* output only at multiples of iOutputFrequency */
-	if ((!force) && (iOutputCount++%iOutputFrequency)) {
+	if ((!force) && !pOutputMeter->dGet()) {
 		return;
 	}
 
