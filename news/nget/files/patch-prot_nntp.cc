--- prot_nntp.cc	2004-12-20 12:44:11.000000000 -0800
+++ prot_nntp.cc	2008-03-02 22:53:40.000000000 -0800
@@ -214,10 +214,9 @@
 			*desc = '\0';
 			desc++;
 			desc += strspn(desc, " \t");
-		}else
-			desc = "";
+		}
 
-		glist->addgroupdesc(connection->server->serverid, cbuf, desc);
+		glist->addgroupdesc(connection->server->serverid, cbuf, desc ? desc : "");
 		done++;
 	}
 	if(quiet<2){
@@ -810,7 +816,7 @@
 	c_nntp_server_article *sa=NULL;
 	float prio;
 	for (sai = part->articles.begin(); sai != part->articles.end(); ++sai){
-		sa=(*sai).second;
+		sa=(*sai);
 		assert(sa);
 		for (t_server_list_range servers = nconfig.getservers(sa->serverid); servers.first!=servers.second; ++servers.first) {
 			const c_server::ptr &s = servers.first->second;
@@ -1012,7 +1018,7 @@
 
 void print_nntp_file_info(c_nntp_file::ptr f, t_show_multiserver show_multi) {
 	char tconvbuf[TCONV_DEF_BUF_LEN];
-	c_nntp_part *p=(*f->parts.begin()).second;
+	c_nntp_part *p=(*f->parts.begin());
 	tconv(tconvbuf,TCONV_DEF_BUF_LEN,&p->date);
 	if (f->iscomplete())
 		printf("%i",f->have);
@@ -1161,7 +1167,7 @@
 		qtotinfo.doarticle_show_multi=gcache_ismultiserver?SHOW_MULTI_SHORT:NO_SHOW_MULTI;
 		c_nntp_part *p;
 //		s_part_u *bp;
-		t_nntp_file_parts::iterator curp;
+		c_nntp_file_parts::iterator curp;
 		char *fn;
 		if (!options.writelite.empty())
 			optionflags |= GETFILES_NODECODE;
@@ -1202,7 +1208,7 @@
 			Decoder decoder;
 			for(curp = f->parts.begin();curp!=f->parts.end();++curp){
 				//asprintf(&fn,"%s/%s-%s-%li-%li-%li",nghome.c_str(),host.c_str(),group.c_str(),fgnum,part,num);
-				p=(*curp).second;
+				p=(*curp);
 				if (dlerr){
 					qtotinfo.bytesleft-=p->bytes();
 					continue;
@@ -1213,9 +1219,9 @@
 						usepath="";
 					else usepath=fr->temppath.c_str();
 					if (optionflags & GETFILES_TEMPSHORTNAMES)
-						asprintf(&fn,"%s%lx.%03i",usepath,f->getfileid(),(*curp).first);
+						asprintf(&fn,"%s%lx.%03i",usepath,f->getfileid(),p->partnum);
 					else
-						asprintf(&fn,"%sngettemp-%lx.%03i",usepath,f->getfileid(),(*curp).first);
+						asprintf(&fn,"%sngettemp-%lx.%03i",usepath,f->getfileid(),p->partnum);
 				}
 				if (!fexists(fn)){
 					ainfo.partreq = f->req;
