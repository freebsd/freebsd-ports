
$FreeBSD$

--- src/parser.y.orig	Sun Dec  1 18:13:36 2002
+++ src/parser.y	Sun Dec  1 18:27:08 2002
@@ -90,6 +90,7 @@
 
 statements	: statement
 		| statements statement
+		;
 
 statement	: logfile
 		| accesslog
@@ -153,6 +154,7 @@
 			yyerrok;
 		  }
 		| L_EOS
+		;
 
 logfile		: LOGFILE string L_EOS {
 			verb_printf("LOGFILE:\t<<%s>>\n", $2);
@@ -208,28 +210,36 @@
 			}
 			free($7);
 		}
+		;
 
 userid		: USERID_T string L_EOS {
 			oops_user = $2;
 		}
+		;
 
 chroot		: CHROOT_T string L_EOS {
 			oops_chroot = $2;
 		}
+		;
 
 blacklist	: BLACKLIST_T num L_EOS {
 			blacklist_len = $2;
 		}
+		;
 
 refuse_at	: REFUSE_AT_T num L_EOS {
 			refuse_at = $2;
 		}
+		;
+
 start_red	: START_RED_T num L_EOS {
 			start_red = $2;
 		}
+		;
 dont_cache_without_last_modified : DONT_CACHE_WITHOUT_LAST_MODIFIED_T L_EOS {
 			dont_cache_without_last_modified = TRUE;
 		}
+		;
 
 insert_x_forwarded_for : INSERT_X_FORWARDED_FOR_T string L_EOS {
 			if ( !strcasecmp(yylval.STRPTR, "yes") )
@@ -241,6 +251,7 @@
 				printf("insert_x_forwarded_for can be 'yes' or 'no'\n");
 			free(yylval.STRPTR);
 		}
+		;
 
 fetch_with_client_speed : FETCH_WITH_CLIENT_SPEED_T string L_EOS {
 			if ( !strcasecmp(yylval.STRPTR, "yes") )
@@ -252,6 +263,7 @@
 				printf("fetch_with_client_speed can be 'yes' or 'no'\n");
 			free(yylval.STRPTR);
 		}
+		;
 
 insert_via	: INSERT_VIA_T string L_EOS {
 			if ( !strcasecmp(yylval.STRPTR, "yes") )
@@ -263,6 +275,7 @@
 				printf("insert_via can be 'yes' or 'no'\n");
 			free(yylval.STRPTR);
 		}
+		;
 
 accesslog	: ACCESSLOG string L_EOS {
 			verb_printf("ACCESSLOG:\t<<%s>>\n", $2);
@@ -320,6 +333,7 @@
 			}
 			free($7);
 		}
+		;
 
 refresh_pattern	: REFRESH_PATTERN_T string num string num L_EOS {
 			char	*buf;
@@ -334,23 +348,32 @@
 			free($2);
 			free($4);
 		}
+		;
+		
 bind_acl	: BIND_ACL_T STRING L_EOS {
 			parse_bind_acl(yylval.STRPTR);
 			free(yylval.STRPTR);
 		}
+		;
 
 acl_allow	: ACL_ALLOW_T STRING L_EOS {
 			parse_acl_access(&acl_allow, yylval.STRPTR);
 			free(yylval.STRPTR);
 		}
+		;
+
 acl_deny	: ACL_DENY_T  STRING L_EOS {
 			parse_acl_access(&acl_deny, yylval.STRPTR);
 			free(yylval.STRPTR);
 		}
+		;
+
 stop_cache_acl	: STOP_CACHE_ACL_T  STRING L_EOS {
 			parse_acl_access(&stop_cache_acl, yylval.STRPTR);
 			free(yylval.STRPTR);
 		}
+		;
+
 acl		: ACL_T	STRING L_EOS {
 			char		  *token, *p, *tptr;
 			char		  *n=NULL, *type=NULL, *data=NULL;
@@ -409,18 +432,21 @@
 		done:;
 			free(yylval.STRPTR);
 		}
+		;
 
 statistics	: STATISTICS STRING L_EOS {
 			verb_printf("STATISTICS:\t<<%s>>\n", yylval.STRPTR);
 			strncpy(statisticslog, yylval.STRPTR, sizeof(statisticslog)-1);
 			free(yylval.STRPTR);
 		}
+		;
 
 pidfile		: PIDFILE STRING L_EOS {
 			verb_printf("PIDFILE:\t<<%s>>\n", yylval.STRPTR);
 			strncpy(pidfile, yylval.STRPTR, sizeof(pidfile)-1);
 			free(yylval.STRPTR);
 		}
+		;
 
 nameserver	: NAMESERVER STRING L_EOS {
 			verb_printf("NAMESERVER:\t<<%s>>\n", yylval.STRPTR);
@@ -438,6 +464,7 @@
 			}
 			free(yylval.STRPTR);
 		}
+		;
 
 connect_from	: CONNECT_FROM STRING L_EOS {
 			char	*p;
@@ -447,83 +474,105 @@
 			while ( *p ) { *p=tolower(*p); p++; }
 			verb_printf("CONNECT_FROM:\t<<%s>>\n", connect_from);
 		}
+		;
 
 stop_cache	: STOP_CACHE STRING L_EOS {
 			verb_printf("STOP_CACHE:\t<<%s>>\n", yylval.STRPTR);
 			add_to_stop_cache(yylval.STRPTR);
 		}
+		;
+
 maxresident	: MAXRESIDENT NUMBER L_EOS {
 			verb_printf("MAXRESIDENT:\t %d\n", yylval.INT);
 			maxresident = yylval.INT;
 		}
+		;
 
 minresident	: MINRESIDENT NUMBER L_EOS {
 			verb_printf("MINRESIDENT:\t %d\n", yylval.INT);
 			minresident = yylval.INT;
 		}
+		;
 
 bind		: BIND_T string L_EOS {
 			bind_addr = $2;
 		}
+		;
 
 http_port	: HTTP_PORT NUMBER L_EOS {
 			verb_printf("HTTP_PORT\t<<%d>>\n", yylval.INT);
 			http_port = yylval.INT;
 		}
+		;
 
 icp_port	: ICP_PORT NUMBER L_EOS {
 			verb_printf("ICP_PORT\t<<%d>>\n", yylval.INT);
 			icp_port = yylval.INT;
 		}
+		;
 
 icp_timeout	: ICP_TIMEOUT NUMBER L_EOS {
 			verb_printf("ICP_TIMEOUT\t<<%d>>\n", yylval.INT);
 			icp_timeout = 1000*yylval.INT;
 		}
+		;
 
 icons_host	: ICONS_HOST STRING L_EOS {
 			verb_printf("ICONS_HOST:\t<<%s>>\n", yylval.STRPTR);
 			strncpy(icons_host, yylval.STRPTR, sizeof(icons_host)-1);
 			free(yylval.STRPTR);
 		}
+		;
 
 icons_port	: ICONS_PORT NUMBER L_EOS {
 			verb_printf("ICONS_PORT:\t<<%d>>\n", yylval.INT);
 			sprintf(icons_port, "%d", yylval.INT);
 		}
+		;
 
 icons_path	: ICONS_PATH STRING L_EOS {
 			verb_printf("ICONS_PATH:\t<<%s>>\n", yylval.STRPTR);
 			strncpy(icons_path, yylval.STRPTR, sizeof(icons_path)-1);
 			free(yylval.STRPTR);
 		}
+		;
 
 always_check_freshness : ALWAYS_CHECK_FRESHNESS_T L_EOS {
 			verb_printf("ALWAYS CHECK FRESHNESS\n");
 			always_check_freshness = TRUE;
 		}
+		;
+
 always_check_freshness_acl : ALWAYS_CHECK_FRESHNESS_ACL_T STRING L_EOS {
 			verb_printf("ALWAYS CHECK FRESHNESS ACL\n");
 			parse_acl_access(&always_check_freshness_acl, yylval.STRPTR);
 			free(yylval.STRPTR);
 		}
+		;
 
 force_http11	: FORCE_HTTP11_T L_EOS {
 			verb_printf("FORCE_HTTP11\n");
 			force_http11 = TRUE;
 		}
+		;
+
 force_completion : FORCE_COMPLETION_T NUMBER L_EOS {
 			verb_printf("FORCE_COMPLETION: %d%%\n", yylval.INT);
 			force_completion = yylval.INT;
 		}
+		;
+
 last_modified_factor : LAST_MODIFIED_FACTOR_T NUMBER L_EOS {
 			verb_printf("LAST_MODIFIED_FACTOR: %d\n", yylval.INT);
 			last_modified_factor = yylval.INT;
 		}
+		;
+
 expire_value	: EXPIRE_VALUE NUMBER L_EOS {
 			verb_printf("EXPIRE_VALUE:\t<<%d days>>\n", yylval.INT);
 			default_expire_value=yylval.INT * 24 * 3600;
 		}
+		;
 
 expiretime	: EXPIRE_TIME_T string_list {
 		    struct	denytime		*denytime;
@@ -537,30 +586,37 @@
 		    }
 		    free_string_list($2);
 		}
+		;
+
 max_expire_value : MAX_EXPIRE_VALUE_T NUMBER L_EOS {
 			verb_printf("MAX_EXPIRE_VALUE:\t<<%d days>>\n", yylval.INT);
 			max_expire_value=yylval.INT * 24 * 3600;
 		}
+		;
 
 ftp_expire_value : FTP_EXPIRE_VALUE_T NUMBER L_EOS {
 			verb_printf("FTP_EXPIRE_VALUE:\t<<%d days>>\n", yylval.INT);
 			ftp_expire_value=yylval.INT * 24 * 3600;
 		}
+		;
 
 expire_interval	: EXPIRE_INTERVAL NUMBER L_EOS {
 			verb_printf("EXPIRE_INTERVAL:<<%d hours>>\n", yylval.INT);
 			default_expire_interval=yylval.INT * 3600;
 		}
+		;
 
 disk_low_free	: DISK_LOW_FREE_T NUMBER L_EOS {
 			verb_printf("DISK_LOW_FREE:\t<<%d %%>>\n", yylval.INT);
 			disk_low_free=yylval.INT ;
 		}
+		;
 
 disk_hi_free	: DISK_HI_FREE_T NUMBER L_EOS {
 			verb_printf("DISK_HI_FREE:\t<<%d %%>>\n", yylval.INT);
 			disk_hi_free=yylval.INT ;
 		}
+		;
 
 parent		: PARENT_T string num L_EOS{
 			verb_printf("PARENT: %s:%d\n", $2, $3);
@@ -568,12 +624,14 @@
 			parent_port = $3;
 			free($2);
 		}
+		;
 
 parent_auth	: PARENT_AUTH_T string L_EOS{
 			verb_printf("PARENT_AUTH: %s\n", $2);
 			parent_auth = base64_encode($2);
 			free($2);
 		}
+		;
 
 local_domain	: LOCAL_DOMAIN_T domainlist L_EOS {
 		    struct domain_list *d;
@@ -591,6 +649,7 @@
 			    }
 			}
 		}
+		;
 
 local_networks	: LOCAL_NETWORKS_T network_list L_EOS {
 		    struct cidr_net *n;
@@ -607,47 +666,55 @@
 			    }
 			}
 		}
+		;
 
 dbhome		: DBHOME STRING L_EOS {
 			printf("WARNING!!!! dbhome must be moved to module berkeley_db\n");
 			free(yylval.STRPTR);
 		}
+		;
 
 dbname		: DBNAME STRING L_EOS {
 			printf("WARNING!!!! dbname must be moved to module berkeley_db\n");
 			free(yylval.STRPTR);
 		}
+		;
 
 db_cache_mem    : DB_CACHE_MEM num L_EOS {
 			printf("WARNING!!!! db_cache_mem must be moved to module berkeley_db\n");
 		}
+		;
 
 mem_max		: MEM_MAX num L_EOS {
 			verb_printf("MEM_MAX:\t<<%d>>\n", $2);
 			mem_max_val = $2 ;
 		}
+		;
 
 lo_mark		: LO_MARK num L_EOS {
 			verb_printf("LO_MARK:\t<<%d>>\n", $2);
 			lo_mark_val = $2 ;
 		}
+		;
 
 swap_advance	: SWAP_ADVANCE_T num L_EOS {
 			verb_printf("SWAP_ADVANCE:\t<<%d>>\n", $2);
 			swap_advance = $2 ;
 			if ( swap_advance <= 0 ) swap_advance = 1;
 		}
+		;
 
 hi_mark		: HI_MARK num L_EOS {
 			verb_printf("HI_MARK:\t<<%d>>\n", $2);
 			hi_mark_val = $2 ;
 		}
+		;
 
-num		: NUMBER { $$ = yylval.INT;}
+num		: NUMBER { $$ = yylval.INT;};
 
-offset		: NUMBER { $$ = yylval.OFFSET;}
+offset		: NUMBER { $$ = yylval.OFFSET;};
 
-string		: STRING { $$ = yylval.STRPTR; }
+string		: STRING { $$ = yylval.STRPTR; };
 
 module		: MODULE module_name '{' mod_ops '}' L_EOS {
 			struct string_list	*list = $4;
@@ -683,6 +750,8 @@
 			if ( mod && mod->config_end ) (*mod->config_end)(0);
 			free($2);
 		}
+		;
+
 mod_ops		: mod_op {
 			$$ = $1;
 			verb_printf("mod_op: %s\n", $$->string);
@@ -694,6 +763,7 @@
 			$$ = $1;
 			verb_printf("mod_op: %s\n", $2->string);
 		}
+		;
 
 mod_op		: string {
 			struct string_list *new = xmalloc(sizeof(*new), "parser: mod_ops");
@@ -711,10 +781,12 @@
 			new->string = new_str;
 			$$=new;
 		}
+		;
 
 module_name	: STRING {
 			$$ = yylval.STRPTR;
 		}
+		;
 
 
 storage		: STORAGE '{' st_ops '}' L_EOS {
@@ -746,6 +818,7 @@
 		    storage_size = 0;
 		    storage_offset = 0;
 		}
+		;
 
 peerconfig	: PEER_PARENT_T ';' {
 			if ( !peerc_ptr )
@@ -803,9 +876,11 @@
 			$1->next = peerc_ptr->acls->deny;
 			peerc_ptr->acls->deny = $1;
 		  }
+		;
 
 peerops		: peerconfig {}
 		| peerops peerconfig {}
+		;
 
 peer		: PEER_T string num num '{' peerops '}' L_EOS {
 			struct	peer *peer,*p;
@@ -837,14 +912,17 @@
 			peer_c.type = PEER_SIBLING;
 			peerc_ptr = NULL;
 		}
+		;
 
 st_ops		: st_op {}
 		| st_op st_ops {}
+		;
 
 st_op		: SIZE offset ';' { storage_size = $2; }
 		| SIZE AUTO_T ';' { storage_size = -1; }
 		| STORAGE_OFFSET_T offset ';' {storage_offset = $2; }
 		| PATH STRING ';' { storage_path = yylval.STRPTR; }
+		;
 
 group		: GROUP group_name '{' group_ops '}' L_EOS {
 			struct	group_ops_struct *ops, *next_ops;
@@ -977,12 +1055,16 @@
                                 g->next = new_grp;
                         }
 		}
+		;
+
 group_name	: STRING {
 			$$ = yylval.STRPTR;
 		}
+		;
 
 group_ops	: group_op { $$ = $1;}
 		| group_op group_ops { $1->next = $2; $$=$1;}
+		;
 
 group_op	: NETWORKS network_list ';' {
 			struct	group_ops_struct	*new;
@@ -1034,6 +1116,7 @@
 		| denytime	{ $$ = $1; }
 		| auth_mods	{ $$ = $1; }
 		| redir_mods	{ $$ = $1; }
+		;
 
 denytime	: DENYTIME_T string_list {
 		    struct	group_ops_struct	*new_op;
@@ -1055,6 +1138,8 @@
 			}
 			free_string_list($2);
 		}
+		;
+
 miss		: MISS_T DENY ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1085,6 +1170,7 @@
 			    $$ = new_op;
 			}
 		}
+		;
 
 auth_mods	: AUTH_MODS_T string_list ';' {
 		    struct	group_ops_struct	*new_op;
@@ -1101,6 +1187,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+		
 redir_mods	: REDIR_MODS_T string_list ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1116,6 +1204,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+
 bandwidth	: BANDWIDTH_T num ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1131,6 +1221,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+		
 per_sess_bw	: PER_SESS_BW_T num ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1146,6 +1238,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+		
 per_ip_bw	: PER_IP_BW_T num ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1161,6 +1255,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+		
 per_ip_conn	: PER_IP_CONN_T num ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1176,6 +1272,8 @@
 			    $$ = new_op;
 			}
 		}
+		;
+		
 conn_from	: CONN_FROM_T string ';' {
 		    struct	group_ops_struct	*new_op;
 
@@ -1205,6 +1303,8 @@
 			$$ = new_op;
 		    }
 		}
+		;
+		
 range		: '[' num ':' num ']'  {
 			if ( !badp_p ) badp_p = &badports[0];
 			badp_p->from = $2;
@@ -1242,9 +1342,11 @@
 			    }
 			    free($2);
 			}
+		;
 
 ranges		: range {}
 		| range ',' ranges {}
+		;
 
 badports	: BADPORTS_T ranges ';' {
 		    struct	group_ops_struct	*new_op;
@@ -1270,6 +1372,7 @@
 			    }
 			}
 		}
+		;
 
 icp		: ICP '{' deny_acls allow_acls '}' {
 			struct	acls			*new_acls;
@@ -1371,6 +1474,7 @@
 				}
 			}
 		}
+		;
 
 http		: HTTP '{' deny_acls allow_acls '}' {
 			struct	acls			*new_acls;
@@ -1472,8 +1576,11 @@
 				}
 			}
 		}
+		;
+
 deny_acls	: deny_acl 			{ $$ = $1; }
 		| deny_acl deny_acls 		{ $2->next = $1 ; $$ = $2; }
+		;
 
 deny_acl	: DENY DSTDOMAIN string_list ';' { 
 			struct acl *new = xmalloc(sizeof(*new), "parser: deny_acl new acl 2");
@@ -1495,9 +1602,11 @@
 			}
 			free_string_list($3);
 		}
+		;
 
 allow_acls	: allow_acl 			{ $$ = $1; }
 		| allow_acl allow_acls 		{ $1->next = $2 ; $$ = $1; }
+		;
 
 allow_acl	: ALLOW  DSTDOMAIN string_list ';' {
 			struct acl *new = xmalloc(sizeof(*new), "parser: allow_acl new acl 2");
@@ -1519,6 +1628,7 @@
 			}
 			free_string_list($3);
 		}
+		;
 
 string_list	: string_list_e { $$ = $1; }
 		| string_list_e string_list {
@@ -1539,6 +1649,7 @@
 				d = d->next;
 			}
 		}
+		;
 
 string_list_e	: string {
 		struct string_list	*new;
@@ -1551,6 +1662,8 @@
 			$$ = new;
 			free($1);
 		}
+		;
+
 domainlist	: domain {
 			struct domain_list *d=$1;
 			verb_printf("<%s>\n", d->domain);
@@ -1588,12 +1701,14 @@
 			new->next = NULL;
 			$$ = new;
 			}
+		;
 
 
 network_list	: network
 		| network network_list {
 			$1->next = $2; $$ = $1;
 		}
+		;
 
 network		: NETWORK {
 			char	*n, *l, *dot, *dot_holder, *t;
@@ -1632,6 +1747,7 @@
 			free(yylval.STRPTR);
 			$$ = new;
 		}
+		;
 
 
 %%
