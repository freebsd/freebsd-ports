--- grouplist.cc	2004-12-20 12:44:10.000000000 -0800
+++ grouplist.cc	2008-03-02 22:53:39.000000000 -0800
@@ -316,7 +316,7 @@
 		return;
 	int nums=0, numsd=0, num=0, numd=0;
 	string tmpfn=filename+".tmp";
-	c_file *f=f=dofileopen(tmpfn,"wb");
+	c_file *f=dofileopen(tmpfn,"wb");
 	try {
 		auto_ptr<c_file> fcloser(f);
 		if (debug){printf("saving grouplist: %lu groups..",(ulong)groups.size());fflush(stdout);}
@@ -330,7 +330,7 @@
 		f->putf(".\n");
 		for (gdi=groups.begin(); gdi!=groups.end(); ++gdi){
 			gd=gdi->second;
-			char *sep="";
+			const char *sep="";
 			for (set<ulong>::iterator sii=gd->serverids.begin(); sii!=gd->serverids.end(); ++sii) {
 				f->putf("%s%lu", sep, *sii);
 				sep=",";
@@ -339,7 +339,7 @@
 			f->putf("\t%s\n",gd->groupname.c_str());
 			for (sgdi=gd->servergroups.begin(); sgdi!=gd->servergroups.end(); ++sgdi) {
 				c_server_group_description::ptr sgd = sgdi->second;
-				char *sep="";
+				const char *sep="";
 				for (set<ulong>::iterator sii=sgd->serverids.begin(); sii!=sgd->serverids.end(); ++sii) {
 					f->putf("%s%lu", sep, *sii);
 					sep=",";
