--- cache.h.orig	2004-05-29 23:00:08 UTC
+++ cache.h
@@ -102,7 +102,7 @@ class c_nntp_server_article {
 		ulong bytes,lines;
 		c_nntp_server_article(ulong serverid,const c_group_info::ptr &group,ulong articlenum,ulong bytes,ulong lines);
 };
-typedef multimap<ulong,c_nntp_server_article*> t_nntp_server_articles;
+typedef vector<c_nntp_server_article*> t_nntp_server_articles;
 typedef pair<c_nntp_server_article*,c_server::ptr> t_real_server_article;
 typedef multimap<float,t_real_server_article,greater<float> > t_nntp_server_articles_prioritized;
 class c_nntp_part {
@@ -118,7 +118,7 @@ class c_nntp_part {
 			c_nntp_server_article *highest_sa=NULL;
 			float highprio=-10000.0,f;
 			for (;nsai!=articles.end();++nsai) {
-				sa=(*nsai).second;
+				sa=(*nsai);
 				for (t_server_list_range servers = nconfig.getservers(sa->serverid); servers.first!=servers.second; ++servers.first)
 					if ((f=nconfig.trustsizes->getserverpriority(servers.first->second)) > highprio){
 						highest_sa=sa;
@@ -137,15 +137,49 @@ class c_nntp_part {
 };
 
 
-typedef map<int,c_nntp_part*> t_nntp_file_parts;
+class c_nntp_file_parts : public vector<c_nntp_part*>
+{
+public:
+	bool haspart(int partnum) const {
+		const_iterator i = lower_bound(partnum);
+		return (i != end() && (*i)->partnum == partnum);
+	}
 
+	c_nntp_part* part(int partnum) {
+		iterator i = lower_bound(partnum);
+		if (i != end() && (*i)->partnum == partnum)
+			return *i;
+		else
+			return NULL;
+	}
+
+	void addpart(c_nntp_part* p) {
+		iterator i = lower_bound(p->partnum);
+		insert(i, p);
+	}
+
+	void removepart(int partnum) {
+		iterator i = lower_bound(partnum);
+		if (i != end() && (*i)->partnum == partnum)
+			erase(i);
+	}
+
+private:
+	iterator lower_bound(int partnum);
+
+	const_iterator lower_bound(int partnum) const
+	{
+		return ((c_nntp_file_parts*)this)->lower_bound(partnum);
+	}
+};
+
 //#define FILEFLAG_READ 1
 
 typedef map<ulong,int> t_server_have_map;
 
 class c_nntp_file : public c_nntp_file_base, public c_refcounted<c_nntp_file>{
 	public:
-		t_nntp_file_parts parts;
+		c_nntp_file_parts parts;
 		int have;
 //		ulong bytes,lines;
 		ulong flags;
@@ -161,13 +195,13 @@ class c_nntp_file : public c_nntp_file_base, public c_
 		bool iscomplete(void) const {return (have>=req) || maybe_a_textreply();}
 		void get_server_have_map(t_server_have_map &have_map) const;
 //		ulong banum(void){assert(!parts.empty());return (*parts.begin()).second->articlenum;}
-		string bamid(void) const {assert(!parts.empty());return (*parts.begin()).second->messageid;}
-		time_t badate(void) const {assert(!parts.empty());return (*parts.begin()).second->date;}
+		string bamid(void) const {assert(!parts.empty());return (*parts.begin())->messageid;}
+		time_t badate(void) const {assert(!parts.empty());return (*parts.begin())->date;}
 #define HAPPYSIZEFUNC2(T)		ulong T(void) const {\
 			ulong b=0;\
-			t_nntp_file_parts::const_iterator nfpi(parts.begin());\
+			c_nntp_file_parts::const_iterator nfpi(parts.begin());\
 			for (;nfpi!=parts.end();++nfpi){\
-				b+=(*nfpi).second->T();\
+				b+=(*nfpi)->T();\
 			}\
 			return b;\
 		}
@@ -228,7 +262,7 @@ class c_message_state : public c_refcounted<c_message_
 };
 
 #ifdef HAVE_WORKING_HASH_MAP
-typedef hash_map<const char*, c_message_state::ptr, hash<const char*>, eqstr> t_message_state_list;
+typedef hash_map<const char*, c_message_state::ptr, std::hash<const char*>, eqstr> t_message_state_list;
 #else
 typedef map<const char*, c_message_state::ptr, ltstr> t_message_state_list;
 #endif
@@ -311,9 +345,9 @@ class meta_mid_info {
 		}
 		void insert(const c_nntp_file::ptr &f){
 			const string &mid=f->bamid();
-			c_nntp_part *p = f->parts.begin()->second;
+			c_nntp_part *p = *(f->parts.begin());
 			for (t_nntp_server_articles::iterator sai=p->articles.begin(); sai!=p->articles.end(); ++sai)
-				midinfos.find(sai->second->group->group)->second->insert(mid);
+				midinfos.find((*sai)->group->group)->second->insert(mid);
 		}
 		void remove(const string &mid){
 			for (t_mid_info_list::iterator mili=midinfos.begin(); mili!=midinfos.end(); ++mili)
