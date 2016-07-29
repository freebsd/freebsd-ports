--- common.c.orig	2008-06-15 07:48:41 UTC
+++ common.c
@@ -265,7 +265,7 @@ dhcp6_add_listval(head, type, val, subli
 	struct dhcp6_listval *lv = NULL;
 
 	if ((lv = malloc(sizeof(*lv))) == NULL) {
-		dprintf(LOG_ERR, FNAME,
+		d_printf(LOG_ERR, FNAME,
 		    "failed to allocate memory for list entry");
 		goto fail;
 	}
@@ -298,7 +298,7 @@ dhcp6_add_listval(head, type, val, subli
 			goto fail;
 		break;
 	default:
-		dprintf(LOG_ERR, FNAME,
+		d_printf(LOG_ERR, FNAME,
 		    "unexpected list value type (%d)", type);
 		goto fail;
 	}
@@ -361,7 +361,7 @@ dhcp6_get_addr(optlen, cp, type, list)
 	void *val;
 
 	if (optlen % sizeof(struct in6_addr) || optlen == 0) {
-		dprintf(LOG_INFO, FNAME,
+		d_printf(LOG_INFO, FNAME,
 		    "malformed DHCP option: type %d, len %d", type, optlen);
 		return -1;
 	}
@@ -371,14 +371,14 @@ dhcp6_get_addr(optlen, cp, type, list)
 		memcpy(&valaddr, val, sizeof(valaddr));
 		if (dhcp6_find_listval(list,
 		    DHCP6_LISTVAL_ADDR6, &valaddr, 0)) {
-			dprintf(LOG_INFO, FNAME, "duplicated %s address (%s)",
+			d_printf(LOG_INFO, FNAME, "duplicated %s address (%s)",
 			    dhcp6optstr(type), in6addr2str(&valaddr, 0));
 			continue;
 		}
 
 		if (dhcp6_add_listval(list, DHCP6_LISTVAL_ADDR6,
 		    &valaddr, NULL) == NULL) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "failed to copy %s address", dhcp6optstr(type));
 			return -1;
 		}
@@ -405,7 +405,7 @@ dhcp6_set_addr(type, list, p, optep, len
 	tmpbuf = NULL;
 	optlen = dhcp6_count_list(list) * sizeof(struct in6_addr);
 	if ((tmpbuf = malloc(optlen)) == NULL) {
-		dprintf(LOG_ERR, FNAME,
+		d_printf(LOG_ERR, FNAME,
 		    "memory allocation failed for %s options",
 		    dhcp6optstr(type));
 		return -1;
@@ -438,10 +438,10 @@ dhcp6_get_domain(optlen, cp, type, list)
 
 		if (dnsdecode((u_char **)(void *)&val,
 		    (u_char *)(cp + optlen), name, sizeof(name)) == NULL) {
-			dprintf(LOG_INFO, FNAME, "failed to "
+			d_printf(LOG_INFO, FNAME, "failed to "
 			    "decode a %s domain name",
 			    dhcp6optstr(type));
-			dprintf(LOG_INFO, FNAME,
+			d_printf(LOG_INFO, FNAME,
 			    "malformed DHCP option: type %d, len %d",
 			     type, optlen);
 			return -1;
@@ -452,7 +452,7 @@ dhcp6_get_domain(optlen, cp, type, list)
 
 		if (dhcp6_add_listval(list,
 		    DHCP6_LISTVAL_VBUF, &vb, NULL) == NULL) {
-			dprintf(LOG_ERR, FNAME, "failed to "
+			d_printf(LOG_ERR, FNAME, "failed to "
 			    "copy a %s domain name", dhcp6optstr(type));
 			return -1;
 		}
@@ -485,7 +485,7 @@ dhcp6_set_domain(type, list, p, optep, l
 
 	tmpbuf = NULL;
 	if ((tmpbuf = malloc(optlen)) == NULL) {
-		dprintf(LOG_ERR, FNAME, "memory allocation failed for "
+		d_printf(LOG_ERR, FNAME, "memory allocation failed for "
 		    "%s domain options", dhcp6optstr(type));
 		return -1;
 	}
@@ -497,14 +497,14 @@ dhcp6_set_domain(type, list, p, optep, l
 		nlen = dnsencode((const char *)d->val_vbuf.dv_buf,
 		    name, sizeof (name));
 		if (nlen < 0) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "failed to encode a %s domain name",
 			    dhcp6optstr(type));
 			free(tmpbuf);
 			return -1;
 		}
 		if (ep - cp < nlen) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "buffer length for %s domain name is too short",
 			    dhcp6optstr(type));
 			free(tmpbuf);
@@ -530,7 +530,7 @@ dhcp6_create_event(ifp, state)
 	struct dhcp6_event *ev;
 
 	if ((ev = malloc(sizeof(*ev))) == NULL) {
-		dprintf(LOG_ERR, FNAME,
+		d_printf(LOG_ERR, FNAME,
 		    "failed to allocate memory for an event");
 		return (NULL);
 	}
@@ -548,7 +548,7 @@ dhcp6_remove_event(ev)
 {
 	struct dhcp6_serverinfo *sp, *sp_next;
 
-	dprintf(LOG_DEBUG, FNAME, "removing an event on %s, state=%s",
+	d_printf(LOG_DEBUG, FNAME, "removing an event on %s, state=%s",
 	    ev->ifp->ifname, dhcp6_event_statestr(ev));
 
 	dhcp6_remove_evdata(ev);
@@ -562,7 +562,7 @@ dhcp6_remove_event(ev)
 	for (sp = ev->servers; sp; sp = sp_next) {
 		sp_next = sp->next;
 
-		dprintf(LOG_DEBUG, FNAME, "removing server (ID: %s)",
+		d_printf(LOG_DEBUG, FNAME, "removing server (ID: %s)",
 		    duidstr(&sp->optinfo.serverID));
 		dhcp6_clear_options(&sp->optinfo);
 		if (sp->authparam != NULL)
@@ -649,14 +649,14 @@ dhcp6_auth_replaycheck(method, prev, cur
 	char bufcurrent[] = "ffff ffff ffff ffff";
 
 	if (method != DHCP6_AUTHRDM_MONOCOUNTER) {
-		dprintf(LOG_ERR, FNAME, "unsupported replay detection "
+		d_printf(LOG_ERR, FNAME, "unsupported replay detection "
 		    "method (%d)", method);
 		return (-1);
 	}
 
 	(void)sprint_uint64(bufprev, sizeof(bufprev), prev);
 	(void)sprint_uint64(bufcurrent, sizeof(bufcurrent), current);
-	dprintf(LOG_DEBUG, FNAME, "previous: %s, current: %s",
+	d_printf(LOG_DEBUG, FNAME, "previous: %s, current: %s",
 	    bufprev, bufcurrent);
 
 	prev = ntohq(prev);
@@ -667,7 +667,7 @@ dhcp6_auth_replaycheck(method, prev, cur
 	 * whether the serial number is increasing or not.
 	 */
         if (prev == (current ^ 0x8000000000000000ULL)) {
-		dprintf(LOG_INFO, FNAME, "detected a singular point");
+		d_printf(LOG_INFO, FNAME, "detected a singular point");
 		return (1);
 	}
 
@@ -688,7 +688,7 @@ getifaddr(addr, ifnam, prefix, plen, str
 	int error = -1;
 
 	if (getifaddrs(&ifap) != 0) {
-		dprintf(LOG_WARNING, FNAME,
+		d_printf(LOG_WARNING, FNAME,
 			"getifaddrs failed: %s", strerror(errno));
 		return (-1);
 	}
@@ -765,7 +765,7 @@ getifidfromaddr(addr, ifidp)
 	int retval = -1;
 
 	if (getifaddrs(&ifap) != 0) {
-		dprintf(LOG_WARNING, FNAME,
+		d_printf(LOG_WARNING, FNAME,
 			"getifaddrs failed: %s", strerror(errno));
 		return (-1);
 	}
@@ -781,7 +781,7 @@ getifidfromaddr(addr, ifidp)
 
 	if (ifa != NULL) {
 		if ((ifid = if_nametoindex(ifa->ifa_name)) == 0) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "if_nametoindex failed for %s", ifa->ifa_name);
 			goto end;
 		}
@@ -999,20 +999,20 @@ get_duid(idfile, duid)
 	char tmpbuf[256];	/* DUID should be no more than 256 bytes */
 
 	if ((fp = fopen(idfile, "r")) == NULL && errno != ENOENT)
-		dprintf(LOG_NOTICE, FNAME, "failed to open DUID file: %s",
+		d_printf(LOG_NOTICE, FNAME, "failed to open DUID file: %s",
 		    idfile);
 
 	if (fp) {
 		/* decode length */
 		if (fread(&len, sizeof(len), 1, fp) != 1) {
-			dprintf(LOG_ERR, FNAME, "DUID file corrupted");
+			d_printf(LOG_ERR, FNAME, "DUID file corrupted");
 			goto fail;
 		}
 	} else {
 		int l;
 
 		if ((l = gethwid(tmpbuf, sizeof(tmpbuf), NULL, &hwtype)) < 0) {
-			dprintf(LOG_INFO, FNAME,
+			d_printf(LOG_INFO, FNAME,
 			    "failed to get a hardware address");
 			goto fail;
 		}
@@ -1022,18 +1022,18 @@ get_duid(idfile, duid)
 	memset(duid, 0, sizeof(*duid));
 	duid->duid_len = len;
 	if ((duid->duid_id = (char *)malloc(len)) == NULL) {
-		dprintf(LOG_ERR, FNAME, "failed to allocate memory");
+		d_printf(LOG_ERR, FNAME, "failed to allocate memory");
 		goto fail;
 	}
 
 	/* copy (and fill) the ID */
 	if (fp) {
 		if (fread(duid->duid_id, len, 1, fp) != 1) {
-			dprintf(LOG_ERR, FNAME, "DUID file corrupted");
+			d_printf(LOG_ERR, FNAME, "DUID file corrupted");
 			goto fail;
 		}
 
-		dprintf(LOG_DEBUG, FNAME,
+		d_printf(LOG_DEBUG, FNAME,
 		    "extracted an existing DUID from %s: %s",
 		    idfile, duidstr(duid));
 	} else {
@@ -1047,27 +1047,27 @@ get_duid(idfile, duid)
 		dp->dh6_duid1_time = htonl((u_long)(t64 & 0xffffffff));
 		memcpy((void *)(dp + 1), tmpbuf, (len - sizeof(*dp)));
 
-		dprintf(LOG_DEBUG, FNAME, "generated a new DUID: %s",
+		d_printf(LOG_DEBUG, FNAME, "generated a new DUID: %s",
 		    duidstr(duid));
 	}
 
 	/* save the (new) ID to the file for next time */
 	if (!fp) {
 		if ((fp = fopen(idfile, "w+")) == NULL) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "failed to open DUID file for save");
 			goto fail;
 		}
 		if ((fwrite(&len, sizeof(len), 1, fp)) != 1) {
-			dprintf(LOG_ERR, FNAME, "failed to save DUID");
+			d_printf(LOG_ERR, FNAME, "failed to save DUID");
 			goto fail;
 		}
 		if ((fwrite(duid->duid_id, len, 1, fp)) != 1) {
-			dprintf(LOG_ERR, FNAME, "failed to save DUID");
+			d_printf(LOG_ERR, FNAME, "failed to save DUID");
 			goto fail;
 		}
 
-		dprintf(LOG_DEBUG, FNAME, "saved generated DUID to %s",
+		d_printf(LOG_DEBUG, FNAME, "saved generated DUID to %s",
 		    idfile);
 	}
 
@@ -1104,7 +1104,7 @@ getifhwaddr(const char *ifname, char *bu
 	dl_phys_addr_req_t dlpar;
 	dl_phys_addr_ack_t *dlpaa;
 
-	dprintf(LOG_DEBUG, FNAME, "trying %s ppa %d", ifname, ppa);
+	d_printf(LOG_DEBUG, FNAME, "trying %s ppa %d", ifname, ppa);
 
 	if (ifname[0] == '\0')
 		return (-1);
@@ -1239,7 +1239,7 @@ gethwid(buf, len, ifname, hwtypep)
 
 		if ((root = di_init("/", DINFOSUBTREE | DINFOMINOR |
 		    DINFOPROP)) == DI_NODE_NIL) {
-			dprintf(LOG_INFO, FNAME, "di_init failed");
+			d_printf(LOG_INFO, FNAME, "di_init failed");
 			return (-1);
 		}
 		parms.buf = buf;
@@ -1283,7 +1283,7 @@ gethwid(buf, len, ifname, hwtypep)
 		default:
 			continue; /* XXX */
 		}
-		dprintf(LOG_DEBUG, FNAME, "found an interface %s for DUID",
+		d_printf(LOG_DEBUG, FNAME, "found an interface %s for DUID",
 		    ifa->ifa_name);
 		memcpy(buf, LLADDR(sdl), sdl->sdl_alen);
 		l = sdl->sdl_alen; /* sdl will soon be freed */
@@ -1296,7 +1296,7 @@ gethwid(buf, len, ifname, hwtypep)
 		if (sll->sll_hatype != ARPHRD_ETHER)
 			continue;
 		*hwtypep = ARPHRD_ETHER;
-		dprintf(LOG_DEBUG, FNAME, "found an interface %s for DUID",
+		d_printf(LOG_DEBUG, FNAME, "found an interface %s for DUID",
 		    ifa->ifa_name);
 		memcpy(buf, sll->sll_addr, sll->sll_halen);
 		l = sll->sll_halen; /* sll will soon be freed */
@@ -1512,12 +1512,12 @@ dhcp6_get_options(p, ep, optinfo)
 		cp = (char *)(p + 1);
 		np = (struct dhcp6opt *)(cp + optlen);
 
-		dprintf(LOG_DEBUG, FNAME, "get DHCP option %s, len %d",
+		d_printf(LOG_DEBUG, FNAME, "get DHCP option %s, len %d",
 		    dhcp6optstr(opt), optlen);
 
 		/* option length field overrun */
 		if (np > ep) {
-			dprintf(LOG_INFO, FNAME, "malformed DHCP options");
+			d_printf(LOG_INFO, FNAME, "malformed DHCP options");
 			goto fail;
 		}
 
@@ -1527,10 +1527,10 @@ dhcp6_get_options(p, ep, optinfo)
 				goto malformed;
 			duid0.duid_len = optlen;
 			duid0.duid_id = cp;
-			dprintf(LOG_DEBUG, "",
+			d_printf(LOG_DEBUG, "",
 				"  DUID: %s", duidstr(&duid0));
 			if (duidcpy(&optinfo->clientID, &duid0)) {
-				dprintf(LOG_ERR, FNAME, "failed to copy DUID");
+				d_printf(LOG_ERR, FNAME, "failed to copy DUID");
 				goto fail;
 			}
 			break;
@@ -1539,9 +1539,9 @@ dhcp6_get_options(p, ep, optinfo)
 				goto malformed;
 			duid0.duid_len = optlen;
 			duid0.duid_id = cp;
-			dprintf(LOG_DEBUG, "", "  DUID: %s", duidstr(&duid0));
+			d_printf(LOG_DEBUG, "", "  DUID: %s", duidstr(&duid0));
 			if (duidcpy(&optinfo->serverID, &duid0)) {
-				dprintf(LOG_ERR, FNAME, "failed to copy DUID");
+				d_printf(LOG_ERR, FNAME, "failed to copy DUID");
 				goto fail;
 			}
 			break;
@@ -1550,14 +1550,14 @@ dhcp6_get_options(p, ep, optinfo)
 				goto malformed;
 			memcpy(&val16, cp, sizeof(val16));
 			num16 = ntohs(val16);
-			dprintf(LOG_DEBUG, "", "  status code: %s",
+			d_printf(LOG_DEBUG, "", "  status code: %s",
 			    dhcp6_stcodestr(num16));
 
 			/* need to check duplication? */
 
 			if (dhcp6_add_listval(&optinfo->stcode_list,
 			    DHCP6_LISTVAL_STCODE, &num16, NULL) == NULL) {
-				dprintf(LOG_ERR, FNAME, "failed to copy "
+				d_printf(LOG_ERR, FNAME, "failed to copy "
 				    "status code");
 				goto fail;
 			}
@@ -1574,13 +1574,13 @@ dhcp6_get_options(p, ep, optinfo)
 				memcpy(&opttype, val, sizeof(u_int16_t));
 				num = (int)ntohs(opttype);
 
-				dprintf(LOG_DEBUG, "",
+				d_printf(LOG_DEBUG, "",
 					"  requested option: %s",
 					dhcp6optstr(num));
 
 				if (dhcp6_find_listval(&optinfo->reqopt_list,
 				    DHCP6_LISTVAL_NUM, &num, 0)) {
-					dprintf(LOG_INFO, FNAME, "duplicated "
+					d_printf(LOG_INFO, FNAME, "duplicated "
 					    "option type (%s)",
 					    dhcp6optstr(opttype));
 					goto nextoption;
@@ -1588,7 +1588,7 @@ dhcp6_get_options(p, ep, optinfo)
 
 				if (dhcp6_add_listval(&optinfo->reqopt_list,
 				    DHCP6_LISTVAL_NUM, &num, NULL) == NULL) {
-					dprintf(LOG_ERR, FNAME,
+					d_printf(LOG_ERR, FNAME,
 					    "failed to copy requested option");
 					goto fail;
 				}
@@ -1599,10 +1599,10 @@ dhcp6_get_options(p, ep, optinfo)
 		case DH6OPT_PREFERENCE:
 			if (optlen != 1)
 				goto malformed;
-			dprintf(LOG_DEBUG, "", "  preference: %d",
+			d_printf(LOG_DEBUG, "", "  preference: %d",
 			    (int)*(u_char *)cp);
 			if (optinfo->pref != DH6OPT_PREF_UNDEF) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated preference option");
 			} else
 				optinfo->pref = (int)*(u_char *)cp;
@@ -1612,11 +1612,11 @@ dhcp6_get_options(p, ep, optinfo)
 				goto malformed;
 			memcpy(&val16, cp, sizeof(val16));
 			val16 = ntohs(val16);
-			dprintf(LOG_DEBUG, "", "  elapsed time: %lu",
+			d_printf(LOG_DEBUG, "", "  elapsed time: %lu",
 			    (u_int32_t)val16);
 			if (optinfo->elapsed_time !=
 			    DH6OPT_ELAPSED_TIME_UNDEF) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated elapsed time option");
 			} else
 				optinfo->elapsed_time = val16;
@@ -1637,7 +1637,7 @@ dhcp6_get_options(p, ep, optinfo)
 			 * [RFC3315 Section 21.4.2]
 			 */
 			if (optinfo->authproto != DHCP6_AUTHPROTO_UNDEF) {
-				dprintf(LOG_INFO, FNAME, "found more than one "
+				d_printf(LOG_INFO, FNAME, "found more than one "
 				    "authentication option");
 				goto fail;
 			}
@@ -1648,7 +1648,7 @@ dhcp6_get_options(p, ep, optinfo)
 			memcpy(&optinfo->authrd, cp, sizeof(optinfo->authrd));
 			cp += sizeof(optinfo->authrd);
 
-			dprintf(LOG_DEBUG, "", "  %s", sprint_auth(optinfo));
+			d_printf(LOG_DEBUG, "", "  %s", sprint_auth(optinfo));
 
 			authinfolen =
 			    optlen - (sizeof(struct dhcp6opt_auth) - 4);
@@ -1670,7 +1670,7 @@ dhcp6_get_options(p, ep, optinfo)
 				optinfo->delayedauth_realmval =
 				    malloc(optinfo->delayedauth_realmlen);
 				if (optinfo->delayedauth_realmval == NULL) {
-					dprintf(LOG_WARNING, FNAME, "failed "
+					d_printf(LOG_WARNING, FNAME, "failed "
 					    "allocate memory for auth realm");
 					goto fail;
 				}
@@ -1687,7 +1687,7 @@ dhcp6_get_options(p, ep, optinfo)
 				optinfo->delayedauth_offset = cp - bp;
 				cp += 16;
 
-				dprintf(LOG_DEBUG, "", "  auth key ID: %x, "
+				d_printf(LOG_DEBUG, "", "  auth key ID: %x, "
 				    "offset=%d, realmlen=%d",
 				    optinfo->delayedauth_keyid,
 				    optinfo->delayedauth_offset,
@@ -1698,7 +1698,7 @@ dhcp6_get_options(p, ep, optinfo)
 				break;
 #endif
 			default:
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "unsupported authentication protocol: %d",
 				    *cp);
 				goto fail;
@@ -1779,14 +1779,14 @@ dhcp6_get_options(p, ep, optinfo)
 			ia.t1 = ntohl(optia.dh6_ia_t1);
 			ia.t2 = ntohl(optia.dh6_ia_t2);
 
-			dprintf(LOG_DEBUG, "",
+			d_printf(LOG_DEBUG, "",
 			    "  IA_PD: ID=%lu, T1=%lu, T2=%lu",
 			    ia.iaid, ia.t1, ia.t2);
 
 			/* duplication check */
 			if (dhcp6_find_listval(&optinfo->iapd_list,
 			    DHCP6_LISTVAL_IAPD, &ia, 0)) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated IA_PD %lu", ia.iaid);
 				break; /* ignore this IA_PD */
 			}
@@ -1813,7 +1813,7 @@ dhcp6_get_options(p, ep, optinfo)
 				goto malformed;
 			memcpy(&val32, cp, sizeof(val32));
 			val32 = ntohl(val32);
-			dprintf(LOG_DEBUG, "",
+			d_printf(LOG_DEBUG, "",
 			    "   information refresh time: %lu", val32);
 			if (val32 < DHCP6_IRT_MINIMUM) {
 				/*
@@ -1823,13 +1823,13 @@ dhcp6_get_options(p, ep, optinfo)
 				 * [draft-ietf-dhc-lifetime-02.txt,
 				 *  Section 3.2]
 				 */
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "refresh time is too small (%d), adjusted",
 				    val32);
 				val32 = DHCP6_IRT_MINIMUM;
 			}
 			if (optinfo->refreshtime != DH6OPT_REFRESHTIME_UNDEF) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated refresh time option");
 			} else
 				optinfo->refreshtime = (int64_t)val32;
@@ -1843,14 +1843,14 @@ dhcp6_get_options(p, ep, optinfo)
 			ia.t1 = ntohl(optia.dh6_ia_t1);
 			ia.t2 = ntohl(optia.dh6_ia_t2);
 
-			dprintf(LOG_DEBUG, "",
+			d_printf(LOG_DEBUG, "",
 			    "  IA_NA: ID=%lu, T1=%lu, T2=%lu",
 			    ia.iaid, ia.t1, ia.t2);
 
 			/* duplication check */
 			if (dhcp6_find_listval(&optinfo->iana_list,
 			    DHCP6_LISTVAL_IANA, &ia, 0)) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated IA_NA %lu", ia.iaid);
 				break; /* ignore this IA_NA */
 			}
@@ -1874,7 +1874,7 @@ dhcp6_get_options(p, ep, optinfo)
 			break;
 		default:
 			/* no option specific behavior */
-			dprintf(LOG_INFO, FNAME,
+			d_printf(LOG_INFO, FNAME,
 			    "unknown or unexpected DHCP6 option %s, len %d",
 			    dhcp6optstr(opt), optlen);
 			break;
@@ -1884,7 +1884,7 @@ dhcp6_get_options(p, ep, optinfo)
 	return (0);
 
   malformed:
-	dprintf(LOG_INFO, FNAME, "malformed DHCP option: type %d, len %d",
+	d_printf(LOG_INFO, FNAME, "malformed DHCP option: type %d, len %d",
 	    opt, optlen);
   fail:
 	dhcp6_clear_options(optinfo);
@@ -1967,11 +1967,11 @@ copyin_option(type, p, ep, list)
 		cp = (char *)(p + 1);
 		np = (struct dhcp6opt *)(cp + optlen);
 
-		dprintf(LOG_DEBUG, FNAME, "get DHCP option %s, len %d",
+		d_printf(LOG_DEBUG, FNAME, "get DHCP option %s, len %d",
 		    dhcp6optstr(opt), optlen);
 
 		if (np > ep) {
-			dprintf(LOG_INFO, FNAME, "malformed DHCP option");
+			d_printf(LOG_INFO, FNAME, "malformed DHCP option");
 			goto fail;
 		}
 
@@ -1979,7 +1979,7 @@ copyin_option(type, p, ep, list)
 		case DH6OPT_IA_PD_PREFIX:
 			/* check option context */
 			if (type != DH6OPT_IA_PD) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "%s is an invalid position for %s",
 				    dhcp6optstr(type), dhcp6optstr(opt));
 				goto fail;
@@ -1991,7 +1991,7 @@ copyin_option(type, p, ep, list)
 			/* copy and convert option values */
 			memcpy(&opt_iapd_prefix, p, sizeof(opt_iapd_prefix));
 			if (opt_iapd_prefix.dh6_iapd_prefix_prefix_len > 128) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "invalid prefix length (%d)",
 				    opt_iapd_prefix.dh6_iapd_prefix_prefix_len);
 				goto malformed;
@@ -2006,7 +2006,7 @@ copyin_option(type, p, ep, list)
 			/* clear padding bits in the prefix address */
 			prefix6_mask(&iapd_prefix.addr, iapd_prefix.plen);
 
-			dprintf(LOG_DEBUG, FNAME, "  IA_PD prefix: "
+			d_printf(LOG_DEBUG, FNAME, "  IA_PD prefix: "
 			    "%s/%d pltime=%lu vltime=%lu",
 			    in6addr2str(&iapd_prefix.addr, 0),
 			    iapd_prefix.plen,
@@ -2014,7 +2014,7 @@ copyin_option(type, p, ep, list)
 
 			if (dhcp6_find_listval(list, DHCP6_LISTVAL_PREFIX6,
 			    &iapd_prefix, 0)) {
-				dprintf(LOG_INFO, FNAME, 
+				d_printf(LOG_INFO, FNAME, 
 				    "duplicated IA_PD prefix "
 				    "%s/%d pltime=%lu vltime=%lu",
 				    in6addr2str(&iapd_prefix.addr, 0),
@@ -2041,7 +2041,7 @@ copyin_option(type, p, ep, list)
 		case DH6OPT_IAADDR:
 			/* check option context */
 			if (type != DH6OPT_IA_NA) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "%s is an invalid position for %s",
 				    dhcp6optstr(type), dhcp6optstr(opt));
 				goto fail;
@@ -2057,14 +2057,14 @@ copyin_option(type, p, ep, list)
 			memcpy(&ia_addr.addr, &opt_ia_addr.dh6_ia_addr_addr,
 			    sizeof(ia_addr.addr));
 
-			dprintf(LOG_DEBUG, FNAME, "  IA_NA address: "
+			d_printf(LOG_DEBUG, FNAME, "  IA_NA address: "
 			    "%s pltime=%lu vltime=%lu",
 			    in6addr2str(&ia_addr.addr, 0),
 			    ia_addr.pltime, ia_addr.vltime);
 
 			if (dhcp6_find_listval(list,
 			    DHCP6_LISTVAL_STATEFULADDR6, &ia_addr, 0)) {
-				dprintf(LOG_INFO, FNAME, 
+				d_printf(LOG_INFO, FNAME, 
 				    "duplicated IA_NA address"
 				    "%s pltime=%lu vltime=%lu",
 				    in6addr2str(&ia_addr.addr, 0),
@@ -2093,7 +2093,7 @@ copyin_option(type, p, ep, list)
 			    type != DH6OPT_IA_PD_PREFIX &&
 			    type != DH6OPT_IA_NA &&
 			    type != DH6OPT_IAADDR) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "%s is an invalid position for %s",
 				    dhcp6optstr(type), dhcp6optstr(opt));
 				goto nextoption; /* or discard the message? */
@@ -2107,13 +2107,13 @@ copyin_option(type, p, ep, list)
 			opt_stcode.dh6_stcode_code =
 			    ntohs(opt_stcode.dh6_stcode_code);
 
-			dprintf(LOG_DEBUG, "", "  status code: %s",
+			d_printf(LOG_DEBUG, "", "  status code: %s",
 			    dhcp6_stcodestr(opt_stcode.dh6_stcode_code));
 
 			/* duplication check */
 			if (dhcp6_find_listval(list, DHCP6_LISTVAL_STCODE,
 			    &opt_stcode.dh6_stcode_code, 0)) {
-				dprintf(LOG_INFO, FNAME,
+				d_printf(LOG_INFO, FNAME,
 				    "duplicated status code (%d)",
 				    opt_stcode.dh6_stcode_code);
 				goto nextoption;
@@ -2133,7 +2133,7 @@ copyin_option(type, p, ep, list)
 	return (0);
 
   malformed:
-	dprintf(LOG_INFO, "", "  malformed DHCP option: type %d", opt);
+	d_printf(LOG_INFO, "", "  malformed DHCP option: type %d", opt);
 
   fail:
 	dhcp6_clear_list(&sublist);
@@ -2221,7 +2221,7 @@ copy_option(type, len, val, optp, ep, to
 	struct dhcp6opt *opt = *optp, opth;
 
 	if ((void *)ep - (void *)optp < len + sizeof(struct dhcp6opt)) {
-		dprintf(LOG_INFO, FNAME,
+		d_printf(LOG_INFO, FNAME,
 		    "option buffer short for %s", dhcp6optstr(type));
 		return (-1);
 	}
@@ -2233,7 +2233,7 @@ copy_option(type, len, val, optp, ep, to
 
 	*optp = (struct dhcp6opt *)((char *)(opt + 1) + len);
  	*totallenp += sizeof(struct dhcp6opt) + len;
-	dprintf(LOG_DEBUG, FNAME, "set %s (len %d)", dhcp6optstr(type), len);
+	d_printf(LOG_DEBUG, FNAME, "set %s (len %d)", dhcp6optstr(type), len);
 
 	return (0);
 }
@@ -2269,21 +2269,21 @@ dhcp6_set_options(type, optbp, optep, op
 
 		tmpbuf = NULL;
 		if ((optlen = copyout_option(NULL, NULL, op)) < 0) {
-			dprintf(LOG_INFO, FNAME,
+			d_printf(LOG_INFO, FNAME,
 			    "failed to count option length");
 			goto fail;
 		}
 		if ((void *)optep - (void *)p < optlen) {
-			dprintf(LOG_INFO, FNAME, "short buffer");
+			d_printf(LOG_INFO, FNAME, "short buffer");
 			goto fail;
 		}
 		if ((tmpbuf = malloc(optlen)) == NULL) {
-			dprintf(LOG_NOTICE, FNAME,
+			d_printf(LOG_NOTICE, FNAME,
 			    "memory allocation failed for IA_NA options");
 			goto fail;
 		}
 		if (copyout_option(tmpbuf, tmpbuf + optlen, op) < 0) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "failed to construct an IA_NA option");
 			goto fail;
 		}
@@ -2340,7 +2340,7 @@ dhcp6_set_options(type, optbp, optep, op
 		buflen = dhcp6_count_list(&optinfo->reqopt_list) *
 			sizeof(u_int16_t);
 		if ((tmpbuf = malloc(buflen)) == NULL) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "memory allocation failed for options");
 			goto fail;
 		}
@@ -2355,7 +2355,7 @@ dhcp6_set_options(type, optbp, optep, op
 			 */
 			if (opt->val_num == DH6OPT_REFRESHTIME &&
 			    type != DH6_INFORM_REQ) {
-				dprintf(LOG_DEBUG, FNAME,
+				d_printf(LOG_DEBUG, FNAME,
 				    "refresh time option is not requested "
 				    "for %s", dhcp6msgstr(type));
 			}
@@ -2423,21 +2423,21 @@ dhcp6_set_options(type, optbp, optep, op
 
 		tmpbuf = NULL;
 		if ((optlen = copyout_option(NULL, NULL, op)) < 0) {
-			dprintf(LOG_INFO, FNAME,
+			d_printf(LOG_INFO, FNAME,
 			    "failed to count option length");
 			goto fail;
 		}
 		if ((void *)optep - (void *)p < optlen) {
-			dprintf(LOG_INFO, FNAME, "short buffer");
+			d_printf(LOG_INFO, FNAME, "short buffer");
 			goto fail;
 		}
 		if ((tmpbuf = malloc(optlen)) == NULL) {
-			dprintf(LOG_NOTICE, FNAME,
+			d_printf(LOG_NOTICE, FNAME,
 			    "memory allocation failed for IA_PD options");
 			goto fail;
 		}
 		if (copyout_option(tmpbuf, tmpbuf + optlen, op) < 0) {
-			dprintf(LOG_ERR, FNAME,
+			d_printf(LOG_ERR, FNAME,
 			    "failed to construct an IA_PD option");
 			goto fail;
 		}
@@ -2492,13 +2492,13 @@ dhcp6_set_options(type, optbp, optep, op
 				break;
 #endif
 			default:
-				dprintf(LOG_ERR, FNAME,
+				d_printf(LOG_ERR, FNAME,
 				    "unexpected authentication protocol");
 				goto fail;
 			}
 		}
 		if ((auth = malloc(authlen)) == NULL) {
-			dprintf(LOG_WARNING, FNAME, "failed to allocate "
+			d_printf(LOG_WARNING, FNAME, "failed to allocate "
 			    "memory for authentication information");
 			goto fail;
 		}
@@ -2534,7 +2534,7 @@ dhcp6_set_options(type, optbp, optep, op
 				optinfo->delayedauth_offset =
 				    ((char *)p - (char *)optbp) + authlen - 16;
 
-				dprintf(LOG_DEBUG, FNAME,
+				d_printf(LOG_DEBUG, FNAME,
 				    "key ID %x, offset %d",
 				    optinfo->delayedauth_keyid,
 				    optinfo->delayedauth_offset); 
@@ -2543,7 +2543,7 @@ dhcp6_set_options(type, optbp, optep, op
 			case DHCP6_AUTHPROTO_RECONFIG:
 #endif
 			default:
-				dprintf(LOG_ERR, FNAME,
+				d_printf(LOG_ERR, FNAME,
 				    "unexpected authentication protocol");
 				free(auth);
 				goto fail;
@@ -2695,7 +2695,7 @@ copyout_option(p, ep, optval)
 		 * we encounter an unknown option.  this should be an internal
 		 * error.
 		 */
-		dprintf(LOG_ERR, FNAME, "unknown option: code %d",
+		d_printf(LOG_ERR, FNAME, "unknown option: code %d",
 		    optval->type);
 		return (-1);
 	}
@@ -2721,7 +2721,7 @@ copyout_option(p, ep, optval)
 	if (!p)
 		return(optlen);
 
-	dprintf(LOG_DEBUG, FNAME, "set %s", dhcp6optstr(opttype));
+	d_printf(LOG_DEBUG, FNAME, "set %s", dhcp6optstr(opttype));
 	if (ep - p < headlen) /* check it just in case */
 		return (-1);
 
@@ -2812,7 +2812,7 @@ dhcp6_set_timeoparam(ev)
 		ev->max_retrans_cnt = REL_MAX_RC;
 		break;
 	default:
-		dprintf(LOG_ERR, FNAME, "unexpected event state %d on %s",
+		d_printf(LOG_ERR, FNAME, "unexpected event state %d on %s",
 		    ev->state, ev->ifp->ifname);
 		exit(1);
 	}
@@ -2870,7 +2870,7 @@ dhcp6_reset_timer(ev)
 
 	statestr = dhcp6_event_statestr(ev);
 
-	dprintf(LOG_DEBUG, FNAME, "reset a timer on %s, "
+	d_printf(LOG_DEBUG, FNAME, "reset a timer on %s, "
 		"state=%s, timeo=%d, retrans=%d",
 		ev->ifp->ifname, statestr, ev->timeouts, ev->retrans);
 }
@@ -2881,7 +2881,7 @@ duidcpy(dd, ds)
 {
 	dd->duid_len = ds->duid_len;
 	if ((dd->duid_id = malloc(dd->duid_len)) == NULL) {
-		dprintf(LOG_ERR, FNAME, "memory allocation failed");
+		d_printf(LOG_ERR, FNAME, "memory allocation failed");
 		return (-1);
 	}
 	memcpy(dd->duid_id, ds->duid_id, dd->duid_len);
@@ -2929,17 +2929,17 @@ get_rdvalue(rdm, rdvalue, rdsize)
 	u_int32_t u32, l32;
 
 	if (rdm != DHCP6_AUTHRDM_MONOCOUNTER) {
-		dprintf(LOG_INFO, FNAME, "unsupported RDM (%d)", rdm);
+		d_printf(LOG_INFO, FNAME, "unsupported RDM (%d)", rdm);
 		return (-1);
 	}
 	if (rdsize != sizeof(u_int64_t)) {
-		dprintf(LOG_INFO, FNAME, "unsupported RD size (%d)", rdsize);
+		d_printf(LOG_INFO, FNAME, "unsupported RD size (%d)", rdsize);
 		return (-1);
 	}
 
 #if defined(HAVE_CLOCK_GETTIME)
 	if (clock_gettime(CLOCK_REALTIME, &tp)) {
-		dprintf(LOG_WARNING, FNAME, "clock_gettime failed: %s",
+		d_printf(LOG_WARNING, FNAME, "clock_gettime failed: %s",
 		    strerror(errno));
 		return (-1);
 	}
@@ -2952,7 +2952,7 @@ get_rdvalue(rdm, rdvalue, rdsize)
 	l32 = (u_int32_t)nsec;
 #else
 	if (gettimeofday(&tv, NULL) != 0) {
-		dprintf(LOG_WARNING, FNAME, "gettimeofday failed: %s",
+		d_printf(LOG_WARNING, FNAME, "gettimeofday failed: %s",
 		    strerror(errno));
 		return (-1);
 	}
@@ -3202,12 +3202,15 @@ setloglevel(debuglevel)
 		case 1:
 			setlogmask(LOG_UPTO(LOG_INFO));
 			break;
+		case 2:
+			setlogmask(LOG_UPTO(LOG_DEBUG));
+			break;
 		}
 	}
 }
 
 void
-dprintf(int level, const char *fname, const char *fmt, ...)
+d_printf(int level, const char *fname, const char *fmt, ...)
 {
 	va_list ap;
 	char logbuf[LINE_MAX];
@@ -3293,7 +3296,7 @@ ifaddrconf(cmd, ifname, addr, plen, plti
 	}
 
 	if ((s = socket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
-		dprintf(LOG_ERR, FNAME, "can't open a temporary socket: %s",
+		d_printf(LOG_ERR, FNAME, "can't open a temporary socket: %s",
 		    strerror(errno));
 		return (-1);
 	}
@@ -3311,7 +3314,7 @@ ifaddrconf(cmd, ifname, addr, plen, plti
 	memset(&ifr, 0, sizeof(ifr));
 	strncpy(ifr.ifr_name, ifname, IFNAMSIZ - 1);
 	if (ioctl(s, SIOGIFINDEX, &ifr) < 0) {
-		dprintf(LOG_NOTICE, FNAME, "failed to get the index of %s: %s",
+		d_printf(LOG_NOTICE, FNAME, "failed to get the index of %s: %s",
 		    ifname, strerror(errno));
 		close(s); 
 		return (-1); 
@@ -3325,7 +3328,7 @@ ifaddrconf(cmd, ifname, addr, plen, plti
 #endif
 
 	if (ioctl(s, ioctl_cmd, &req)) {
-		dprintf(LOG_NOTICE, FNAME, "failed to %s an address on %s: %s",
+		d_printf(LOG_NOTICE, FNAME, "failed to %s an address on %s: %s",
 		    cmdstr, ifname, strerror(errno));
 		close(s);
 		return (-1);
@@ -3334,14 +3337,14 @@ ifaddrconf(cmd, ifname, addr, plen, plti
 #ifdef __sun__
 	memcpy(&req.lifr_addr, addr, sizeof (*addr));
 	if (ioctl(s, SIOCSLIFADDR, &req) == -1) {
-		dprintf(LOG_NOTICE, FNAME, "failed to %s new address on %s: %s",
+		d_printf(LOG_NOTICE, FNAME, "failed to %s new address on %s: %s",
 		    cmdstr, ifname, strerror(errno));
 		close(s);
 		return (-1);
 	}
 #endif
 
-	dprintf(LOG_DEBUG, FNAME, "%s an address %s/%d on %s", cmdstr,
+	d_printf(LOG_DEBUG, FNAME, "%s an address %s/%d on %s", cmdstr,
 	    addr2str((struct sockaddr *)addr), plen, ifname);
 
 	close(s);
@@ -3357,13 +3360,13 @@ safefile(path)
 
 	/* no setuid */
 	if (getuid() != geteuid()) {
-		dprintf(LOG_NOTICE, FNAME,
+		d_printf(LOG_NOTICE, FNAME,
 		    "setuid'ed execution not allowed");
 		return (-1);
 	}
 
 	if (lstat(path, &s) != 0) {
-		dprintf(LOG_NOTICE, FNAME, "lstat failed: %s",
+		d_printf(LOG_NOTICE, FNAME, "lstat failed: %s",
 		    strerror(errno));
 		return (-1);
 	}
@@ -3371,7 +3374,7 @@ safefile(path)
 	/* the file must be owned by the running uid */
 	myuid = getuid();
 	if (s.st_uid != myuid) {
-		dprintf(LOG_NOTICE, FNAME, "%s has invalid owner uid", path);
+		d_printf(LOG_NOTICE, FNAME, "%s has invalid owner uid", path);
 		return (-1);
 	}
 
@@ -3379,7 +3382,7 @@ safefile(path)
 	case S_IFREG:
 		break;
 	default:
-		dprintf(LOG_NOTICE, FNAME, "%s is an invalid file type 0x%o",
+		d_printf(LOG_NOTICE, FNAME, "%s is an invalid file type 0x%o",
 		    path, (s.st_mode & S_IFMT));
 		return (-1);
 	}
