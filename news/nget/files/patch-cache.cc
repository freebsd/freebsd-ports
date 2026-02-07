--- cache.cc	2004-05-29 16:00:05.000000000 -0700
+++ cache.cc	2005-09-22 22:37:43.000000000 -0700
@@ -133,37 +133,63 @@
 	c_nntp_server_article *sa;
 #ifndef NDEBUG
 	if (debug>=DEBUG_MIN){
-		t_nntp_server_articles::iterator sai=articles.find(h->serverid);
-		if (sai!=articles.end()){
-			sa=(*sai).second;
-			printf("adding server_article we already have %lu %lu %lu %lu(%lu %lu %lu %lu)\n",h->serverid,h->articlenum,h->bytes,h->lines,sa->serverid,sa->articlenum,sa->bytes,sa->lines);
-			//		return;//could be useful, lets add it.
+		t_nntp_server_articles::iterator sai=articles.begin();
+		for (;sai!=articles.end();++sai){
+			if ((*sai)->serverid == h->serverid)
+			{
+				sa=(*sai);
+				printf("adding server_article we already have %lu %lu %lu %lu(%lu %lu %lu %lu)\n",h->serverid,h->articlenum,h->bytes,h->lines,sa->serverid,sa->articlenum,sa->bytes,sa->lines);
+				//		return;//could be useful, lets add it.
+			}
 		}
 	}
 	if (h->date!=date)
 		printf("adding server_article with different date, date=%li h->date=%li mid=%s\n",date,h->date,h->messageid.c_str());
 #endif
 	sa=new c_nntp_server_article(h->serverid,h->group,h->articlenum,h->bytes,h->lines);
-	articles.insert(t_nntp_server_articles::value_type(h->serverid,sa));
+	articles.push_back(sa);
 }
 
 c_nntp_part::~c_nntp_part(){
 	t_nntp_server_articles::iterator i;
 	for(i = articles.begin();i!=articles.end();++i){
-		assert((*i).second);
-		delete (*i).second;
+		assert(*i);
+		delete (*i);
+	}
+}
+
+c_nntp_file_parts::iterator c_nntp_file_parts::lower_bound(int partnum)
+{
+	iterator first = begin();
+	ptrdiff_t len = distance(begin(), end());
+	ptrdiff_t half;
+	iterator middle;
+
+	while (len > 0) { 
+		half = len >> 1;
+		middle = first;
+		advance(middle, half);
+
+		if ((*middle)->partnum < partnum) {
+			first = middle;
+			++first;
+			len = len - half - 1;
+		}
+		else
+			len = half;
 	}
+	return first;
 }
 
+
 void c_nntp_file::addpart(c_nntp_part *p){
 	assert(p);
 	//assert((req==-1 && p->partnum<=0) || (p->partnum<=req));//#### req==-1 hack for old version that set non-multipart messages partnum to 0 instead of -1
 //	parts[p->partnum]=p;
 #ifndef NDEBUG
-	t_nntp_file_parts::iterator nfpi=parts.find(p->partnum);
-	assert(nfpi==parts.end());
+	assert(!parts.haspart(p->partnum));
 #endif
-	parts.insert(t_nntp_file_parts::value_type(p->partnum,p));
+	parts.addpart(p);
 	if (count_partnum(p->partnum, req)) have++;
 //	bytes+=p->apxbytes;lines+=p->apxlines;
 }
@@ -175,43 +201,41 @@
 void c_nntp_file::mergefile(c_nntp_file::ptr &f){
 	if (f->update>update)
 		update=f->update;
-	t_nntp_file_parts::iterator fpi=f->parts.begin();
+	c_nntp_file_parts::iterator fpi=f->parts.begin();
 	while (fpi!=f->parts.end()){
-		const c_nntp_part *p = fpi->second;
-		t_nntp_file_parts::iterator nfpi=parts.find(p->partnum);
-		if (nfpi==parts.end()) {
+		const c_nntp_part *p = (*fpi);
+		c_nntp_part* mp = parts.part(p->partnum);
+		if (mp == NULL) {
 			addpart(new c_nntp_part(p->partnum, p->date, p->messageid));
-			nfpi=parts.find(p->partnum);
+			mp=parts.part(p->partnum);
 		}else{
-			if (nfpi->second->messageid!=p->messageid){
-				PDEBUG(DEBUG_MED,"%s was gonna merge, but already have this part(sub=%s part=%i omid=%s)?\n",p->messageid.c_str(),f->subject.c_str(),p->partnum,nfpi->second->messageid.c_str());
+			if (mp->messageid!=p->messageid){
+				PDEBUG(DEBUG_MED,"%s was gonna merge, but already have this part(sub=%s part=%i omid=%s)?\n",p->messageid.c_str(),f->subject.c_str(),p->partnum,mp->messageid.c_str());
 				++fpi;
 				continue;
 			}
 		}
 		for (t_nntp_server_articles::const_iterator fsai=p->articles.begin(); fsai!=p->articles.end(); ++fsai){
 			
-			c_nntp_server_article *nsa = new c_nntp_server_article(*fsai->second);
-			nfpi->second->articles.insert(t_nntp_server_articles::value_type(nsa->serverid,nsa));
+			c_nntp_server_article *nsa = new c_nntp_server_article(**fsai);
+			mp->articles.push_back(nsa);
 		}
-		t_nntp_file_parts::iterator del_pi = fpi;
-		++fpi;
-		delete del_pi->second;
-		f->parts.erase(del_pi);
+		delete (*fpi);
+		fpi = f->parts.erase(fpi);
 	}
 }
 
 //fill a mapping of how many parts of the file each server has
 void c_nntp_file::get_server_have_map(t_server_have_map &have_map) const{
-	t_nntp_file_parts::const_iterator pi(parts.begin());
+	c_nntp_file_parts::const_iterator pi(parts.begin());
 	for (;pi!=parts.end();++pi){
-		t_nntp_server_articles::const_iterator nsai(pi->second->articles.begin());
+		t_nntp_server_articles::const_iterator nsai((*pi)->articles.begin());
 		ulong serverid;
-		int partnum=pi->second->partnum;
+		int partnum=(*pi)->partnum;
 		set<ulong> servers_already_found;
 
-		for (;nsai!=pi->second->articles.end();++nsai) {
-			serverid=nsai->first;
+		for (;nsai!=(*pi)->articles.end();++nsai) {
+			serverid=(*nsai)->serverid;
 			//don't increment count twice if a server has multiple server_articles for a single part
 			if (servers_already_found.insert(serverid).second){
 				t_server_have_map::iterator hmi(have_map.insert(t_server_have_map::value_type(serverid, 0)).first);
@@ -230,10 +254,10 @@
 }
 
 c_nntp_file::~c_nntp_file(){
-	t_nntp_file_parts::iterator i;
+	c_nntp_file_parts::iterator i;
 	for(i = parts.begin();i!=parts.end();++i){
-		assert((*i).second);
-		delete (*i).second;
+		assert(*i);
+		delete (*i);
 	}
 }
 
@@ -323,9 +347,8 @@
 	for (i=irange.first;i!=irange.second;++i){
 		f=(*i).second;
 		assert(!f.isnull());
-		t_nntp_file_parts::iterator op;
-		if ((op=f->parts.find(h->partnum))!=f->parts.end()){
-			c_nntp_part *matchpart=(*op).second;
+		c_nntp_part* matchpart = f->parts.part(h->partnum);
+		if (matchpart != NULL) {
 			if (matchpart->messageid==h->messageid){
 				matchpart->addserverarticle(h);
 				return 0;
@@ -357,23 +380,22 @@
 void c_nntp_cache::getxrange(c_nntp_server_info *servinfo, c_nrange *range) const {
 	t_nntp_files::const_iterator i;
 	c_nntp_file::ptr nf;
-	t_nntp_file_parts::const_iterator pi;
+	c_nntp_file_parts::const_iterator pi;
 	c_nntp_part *np;
 	pair<t_nntp_server_articles::const_iterator,t_nntp_server_articles::const_iterator> sarange;
-	c_nntp_server_article *sa;
 	for(i = files.begin();i!=files.end();++i){
 		nf=(*i).second;
 		assert(!nf.isnull());
 		assert(!nf->parts.empty());
 		for(pi = nf->parts.begin();pi!=nf->parts.end();++pi){
-			np=(*pi).second;
+			np=(*pi);
 			assert(np);
-			sarange=np->articles.equal_range(servinfo->serverid);
-			while (sarange.first!=sarange.second){
-				sa=(*sarange.first).second;
-				assert(sa);
-				range->remove(sa->articlenum);
-				++sarange.first;
+			t_nntp_server_articles::const_iterator sai = np->articles.begin();
+			for (; sai != np->articles.end(); ++sai){
+				if ((*sai)->serverid == servinfo->serverid)
+				{
+					range->remove((*sai)->articlenum);
+				}
 			}
 		}
 	}
@@ -390,9 +412,8 @@
 	ulong count=0,countp=0,countf=0;
 	t_nntp_files::iterator i,in;
 	c_nntp_file::ptr nf;
-	t_nntp_file_parts::iterator pi,pic;
+	c_nntp_file_parts::iterator pi;
 	c_nntp_part *np;
-	pair<t_nntp_server_articles::iterator,t_nntp_server_articles::iterator> sarange;
 	t_nntp_server_articles::iterator sai;
 	c_nntp_server_article *sa;
 	c_mid_info rel_midinfo("");
@@ -408,32 +429,31 @@
 		nf=(*i).second;
 		assert(!nf.isnull());
 		assert(!nf->parts.empty());
-		for(pi = nf->parts.begin();pi!=nf->parts.end();){
-			pic=pi;
-			++pi;
-			np=(*pic).second;
+		for(pi = nf->parts.end();pi!=nf->parts.begin();){
+			--pi;
+			np=(*pi);
 			assert(np);
-			sarange=np->articles.equal_range(servinfo->serverid);
-			while (sarange.first!=sarange.second){
-				sai=sarange.first;
-				++sarange.first;
-				sa=(*sai).second;
+			for (sai = np->articles.end(); sai != np->articles.begin();) {
+				--sai;
+				sa=*sai;
 				assert(sa);
-				if (flushrange.check(sa->articlenum)){
+				if ((sa->serverid == servinfo->serverid) && flushrange.check(sa->articlenum)){
 					delete sa;
-					np->articles.erase(sai);
-					if (np->articles.empty()){
-						if (count_partnum(np->partnum,nf->req)) nf->have--;
-						midinfo->set_delete(np->messageid);
-						delete np;
-						np=NULL;
-						nf->parts.erase(pic);
-						countp++;
-					}
+					sai = np->articles.erase(sai);
 					count++;
 				}
 			}
-			if (np && midinfo->check(np->messageid)) rel_midinfo.insert(np->messageid);
+			if (np->articles.empty()){
+				if (count_partnum(np->partnum,nf->req)) nf->have--;
+				midinfo->set_delete(np->messageid);
+				delete np;
+				pi = nf->parts.erase(pi);
+				countp++;
+			}
+			else if (midinfo->check(np->messageid))
+			{
+				rel_midinfo.insert(np->messageid);
+			}
 		}
 		if (nf->parts.empty()){
 //			nf->dec_rcount();
@@ -453,12 +473,13 @@
 		assert(!nf.isnull());
 		assert(!nf->parts.empty());
 		for(pi = nf->parts.begin();pi!=nf->parts.end();++pi){
-			np=(*pi).second;
+			np=(*pi);
 			assert(np);
-			sai=np->articles.find(servinfo->serverid);
-			if (sai!=np->articles.end()){
-				sa=(*sai).second;
-				assert(!flushrange.check(sa->articlenum));
+			for (sai=np->articles.begin(); sai != np->articles.end(); ++sai){
+				sa=*sai;
+				if (sa->serverid == servinfo->serverid){
+					assert(!flushrange.check(sa->articlenum));
+				}
 			}
 		}
 	}
@@ -604,7 +625,7 @@
 					if (nconfig.hasserver(serverid)) {
 						sa=new c_nntp_server_article(serverid,group,atoul(t[1]),atoul(t[2]),atoul(t[3]));
 						//np->addserverarticle(sa);
-						np->articles.insert(t_nntp_server_articles::value_type(sa->serverid,sa));
+						np->articles.push_back(sa);
 						counta++;
 					}else
 						countdeada++;
@@ -617,7 +638,7 @@
 		else if (mode==PART_MODE && nf){//new part mode
 			if (np && np->articles.empty()) {
 				midinfo->set_delete(np->messageid);
-				nf->parts.erase(np->partnum);
+				nf->parts.removepart(np->partnum);
 				delete np;
 				np=NULL;
 				count--;
@@ -734,7 +755,7 @@
 				if (quiet<2){printf("saving cache: %lu parts, %lu files..",totalnum,(ulong)files.size());fflush(stdout);}
 				c_nntp_file::ptr nf;
 				t_references::iterator ri;
-				t_nntp_file_parts::iterator pi;
+				c_nntp_file_parts::iterator pi;
 				t_nntp_server_articles::iterator sai;
 				c_nntp_server_article *sa;
 				c_nntp_part *np;
@@ -758,11 +779,11 @@
 					}
 					f->putf(".\n");//end REFERENCES_MODE
 					for(pi = nf->parts.begin();pi!=nf->parts.end();++pi){
-						np=(*pi).second;
+						np=(*pi);
 						assert(np);
 						f->putf("%i\t%lu\t%s\n",np->partnum,np->date,np->messageid.c_str());//PART_MODE
 						for (sai = np->articles.begin(); sai != np->articles.end(); ++sai){
-							sa=(*sai).second;
+							sa=(*sai);
 							assert(sa);
 							f->putf("%lu\t%lu\t%lu\t%lu\n",sa->serverid,sa->articlenum,sa->bytes,sa->lines);//SERVER_ARTICLE_MODE
 							counta++;
