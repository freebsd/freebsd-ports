# New ports collection makefile for:	aolserver
# Version required:	3.0b6
# Date created:		13 January 2000
# Whom:			Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

DISTNAME=	as3b61
PKGNAME=	aolserver-3.0b6.1
CATEGORIES=	www
MASTER_SITES=	http://aolserver.com/download/3.0b61/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	mab@red-bean.com

NO_PACKAGE=	"ignores cflags"

USE_GMAKE=	yes

MAKEFILE=	makefile

MAN3=	ns_absoluteurl.3 ns_abstimedwaitforevent.3 ns_adjtime.3 \
	ns_adpregisterparser.3 ns_allocthreadlocalstorage.3 \
	ns_asctime.3 ns_authorizerequest.3 ns_authorizeuser.3 \
	ns_begindetachedthread.3 ns_beginthread.3 \
	ns_bindsock.3 ns_broadcastevent.3 ns_cachebroadcast.3 \
	ns_cachecreate.3 ns_cachecreateentry.3 \
	ns_cachecreatesz.3 ns_cachedeleteentry.3 \
	ns_cachefind.3 ns_cachefindentry.3 \
	ns_cachefirstentry.3 ns_cacheflush.3 \
	ns_cacheflushentry.3 ns_cachefree.3 \
	ns_cachegetvalue.3 ns_cachekey.3 ns_cachelock.3 \
	ns_cachemalloc.3 ns_cachename.3 ns_cachenextentry.3 \
	ns_cachesetvalue.3 ns_cachesetvaluesz.3 \
	ns_cachesignal.3 ns_cachetimedgetvalue.3 \
	ns_cachetimedwait.3 ns_cacheunlock.3 \
	ns_cacheunsetvalue.3 ns_cachewait.3 ns_calloc.3 \
	ns_checkstack.3 ns_closeonexec.3 ns_condbroadcast.3 \
	ns_conddestroy.3 ns_condinit.3 ns_condsignal.3 \
	ns_condtimedwait.3 ns_condwait.3 ns_configgetbool.3 \
	ns_configgetint.3 ns_configgetint64.3 \
	ns_configgetpath.3 ns_configgetsection.3 \
	ns_configgetsections.3 ns_configgetvalue.3 \
	ns_configgetvalueexact.3 ns_connauthpasswd.3 \
	ns_connauthuser.3 ns_connclose.3 \
	ns_conncondsetheaders.3 ns_connconstructheaders.3 \
	ns_conncontentlength.3 ns_conncontentsent.3 \
	ns_conncopytochannel.3 ns_conncopytodstring.3 \
	ns_conncopytofd.3 ns_conncopytofile.3 \
	ns_conndrivercontext.3 ns_conndrivername.3 \
	ns_connflushcontent.3 ns_connflushheaders.3 \
	ns_conngetquery.3 ns_conngets.3 ns_connheaders.3 \
	ns_connhost.3 ns_conninit.3 ns_connlocation.3 \
	ns_connmodifiedsince.3 ns_connoutputheaders.3 \
	ns_connpeer.3 ns_connpeerport.3 ns_connport.3 \
	ns_connprintfheader.3 ns_connputs.3 ns_connread.3 \
	ns_connreadheaders.3 ns_connreadline.3 \
	ns_connredirect.3 ns_connreplaceheaders.3 \
	ns_connresponselength.3 ns_connresponsestatus.3 \
	ns_connreturnadminnotice.3 ns_connreturnbadrequest.3 \
	ns_connreturndata.3 ns_connreturnfile.3 \
	ns_connreturnforbidden.3 ns_connreturnhtml.3 \
	ns_connreturninternalerror.3 ns_connreturnnoresponse.3 \
	ns_connreturnnotfound.3 ns_connreturnnotice.3 \
	ns_connreturnnotimplemented.3 ns_connreturnnotmodified.3 \
	ns_connreturnok.3 ns_connreturnopenchannel.3 \
	ns_connreturnopenfd.3 ns_connreturnopenfile.3 \
	ns_connreturnredirect.3 ns_connreturnstatus.3 \
	ns_connreturnunauthorized.3 ns_connrunrequest.3 \
	ns_connsendchannel.3 ns_connsenddstring.3 \
	ns_connsendfd.3 ns_connsendfp.3 ns_connserver.3 \
	ns_connsetexpiresheader.3 ns_connsetheaders.3 \
	ns_connsetlastmodifiedheader.3 ns_connsetlengthheader.3 \
	ns_connsetrequiredheaders.3 ns_connsettypeheader.3 \
	ns_connwrite.3 ns_csdestroy.3 ns_csenter.3 \
	ns_csinit.3 ns_csleave.3 ns_ctime.3 ns_db0or1row.3 \
	ns_db1row.3 ns_dbbindrow.3 ns_dbbouncepool.3 \
	ns_dbcancel.3 ns_dbdml.3 ns_dbdriverdbtype.3 \
	ns_dbdrivername.3 ns_dbexec.3 ns_dbflush.3 \
	ns_dbgetrow.3 ns_dbinterpretsqlfile.3 \
	ns_dbpoolallowable.3 ns_dbpooldefault.3 \
	ns_dbpooldescription.3 ns_dbpoolgethandle.3 \
	ns_dbpoolgetmultiplehandles.3 ns_dbpoollist.3 \
	ns_dbpoolputhandle.3 ns_dbpooltimedgethandle.3 \
	ns_dbpooltimedgetmultiplehandles.3 ns_dbquotevalue.3 \
	ns_dbregisterdriver.3 ns_dbselect.3 \
	ns_dbsetexception.3 ns_dbspexec.3 ns_dbspgetparams.3 \
	ns_dbspreturncode.3 ns_dbspsetparam.3 ns_dbspstart.3 \
	ns_decodeurl.3 ns_destroycriticalsection.3 \
	ns_destroyevent.3 ns_destroymutex.3 \
	ns_destroyrwlock.3 ns_destroysemaphore.3 \
	ns_difftime.3 ns_driverenablekeepalive.3 \
	ns_dstringappend.3 ns_dstringappendarg.3 \
	ns_dstringexport.3 ns_dstringfree.3 ns_dstringinit.3 \
	ns_dstringlength.3 ns_dstringnappend.3 \
	ns_dstringprintf.3 ns_dstringtrunc.3 \
	ns_dstringvalue.3 ns_dstringvarappend.3 ns_duphigh.3 \
	ns_encodeurl.3 ns_encrypt.3 ns_entercriticalsection.3 \
	ns_execargblk.3 ns_execargv.3 ns_execproc.3 \
	ns_execprocess.3 ns_exitthread.3 ns_fatal.3 \
	ns_fetchpage.3 ns_fetchurl.3 ns_fork.3 ns_free.3 \
	ns_freerequest.3 ns_getconninterp.3 ns_getdriver.3 \
	ns_getdrivercontext.3 ns_getdriverlabel.3 \
	ns_getdrivername.3 ns_getdriverproc.3 \
	ns_getfirstdriver.3 ns_gethostbyaddr.3 \
	ns_getmimetype.3 ns_getnextdriver.3 ns_getrequest.3 \
	ns_getsockaddr.3 ns_getthread.3 ns_getthreadid.3 \
	ns_getthreadlocalstorage.3 ns_gettime.3 ns_getuid.3 \
	ns_getuserhome.3 ns_gmtime.3 ns_homepath.3 \
	ns_httptime.3 ns_htuudecode.3 ns_htuuencode.3 \
	ns_incrtime.3 ns_inetntoa.3 ns_infoboottime.3 \
	ns_infobuilddate.3 ns_infoconfigfile.3 \
	ns_infoerrorlog.3 ns_infohomepath.3 ns_infohostname.3 \
	ns_infolabel.3 ns_infopid.3 ns_infoplatform.3 \
	ns_infoservername.3 ns_infoserversstarted.3 \
	ns_infoserverversion.3 ns_infoshutdownpending.3 \
	ns_infostarted.3 ns_infouptime.3 \
	ns_initializecriticalsection.3 ns_initializeevent.3 \
	ns_initializemutex.3 ns_initializerwlock.3 \
	ns_initializesemaphore.3 ns_leavecriticalsection.3 \
	ns_libpath.3 ns_localtime.3 ns_lockmutex.3 \
	ns_log.3 ns_log2.3 ns_logroll.3 ns_logtime.3 \
	ns_makepath.3 ns_malloc.3 ns_match.3 ns_modlog.3 \
	ns_modloggetthreshold.3 ns_modloglookuphandle.3 \
	ns_modloglookuprealm.3 ns_modlogredirect.3 \
	ns_modlogregister.3 ns_modlogsetthreshold.3 \
	ns_moduleload.3 ns_modulepath.3 ns_modulesymbol.3 \
	ns_mutexdestroy.3 ns_mutexinit.3 ns_mutexlock.3 \
	ns_mutexunlock.3 ns_nextword.3 ns_normalizepath.3 \
	ns_pageroot.3 ns_parseheader.3 ns_parsehttptime.3 \
	ns_parserequest.3 ns_parseurl.3 ns_pathisabsolute.3 \
	ns_permpasswordcheck.3 ns_poolalloc.3 ns_poolcreate.3 \
	ns_pooldestroy.3 ns_pooldump.3 ns_poolfree.3 \
	ns_poolrealloc.3 ns_pooltrace.3 ns_querytoset.3 \
	ns_queueconn.3 ns_quotehtml.3 ns_readdir.3 \
	ns_readlockrwlock.3 ns_readunlockrwlock.3 \
	ns_realloc.3 ns_registeratexit.3 \
	ns_registeratprestartup.3 ns_registeratsignal.3 \
	ns_registeratstartup.3 ns_registercleanup.3 \
	ns_registerdriver.3 ns_registerfilter.3 \
	ns_registerlocation.3 ns_registerproxyrequest.3 \
	ns_registerrequest.3 ns_registerreturn.3 \
	ns_registerservershutdown.3 ns_registerservertrace.3 \
	ns_registershutdown.3 ns_relativeurl.3 \
	ns_releasesemaphore.3 ns_rollfile.3 \
	ns_rwlockdestroy.3 ns_rwlockinit.3 ns_rwlockrdlock.3 \
	ns_rwlockunlock.3 ns_rwlockwrlock.3 \
	ns_scheduledaily.3 ns_scheduleproc.3 \
	ns_scheduleprocex.3 ns_scheduleweekly.3 \
	ns_semadestroy.3 ns_semainit.3 ns_semapost.3 \
	ns_semawait.3 ns_serverspecificalloc.3 \
	ns_serverspecificdestroy.3 ns_serverspecificget.3 \
	ns_serverspecificset.3 ns_setcopy.3 ns_setcreate.3 \
	ns_setdelete.3 ns_setdeletekey.3 ns_setdriverproc.3 \
	ns_setevent.3 ns_setfind.3 ns_setfree.3 \
	ns_setget.3 ns_setideletekey.3 ns_setifind.3 \
	ns_setiget.3 ns_setiunique.3 ns_setkey.3 \
	ns_setlast.3 ns_setlistfind.3 ns_setlistfree.3 \
	ns_setmerge.3 ns_setmove.3 ns_setname.3 \
	ns_setprint.3 ns_setput.3 ns_setputvalue.3 \
	ns_setrequestauthorizeproc.3 ns_setrequesturl.3 \
	ns_setsize.3 ns_setsplit.3 ns_setthreadlocalstorage.3 \
	ns_settrunc.3 ns_setunique.3 ns_setupdate.3 \
	ns_seturltofileproc.3 ns_setuserauthorizeproc.3 \
	ns_setvalue.3 ns_sigmask.3 ns_signal.3 \
	ns_sigwait.3 ns_skipurl.3 ns_sockasyncconnect.3 \
	ns_sockcallback.3 ns_sockcancelcallback.3 \
	ns_sockconnect.3 ns_socklisten.3 \
	ns_socklistencallback.3 ns_sockpipe.3 \
	ns_sockportbound.3 ns_socksetblocking.3 \
	ns_socksetnonblocking.3 ns_socktimedconnect.3 \
	ns_strcasefind.3 ns_strcopy.3 ns_strdup.3 \
	ns_stringprint.3 ns_strtok.3 ns_strtolower.3 \
	ns_strtoupper.3 ns_strtrim.3 ns_strtrimleft.3 \
	ns_strtrimright.3 ns_tclallocateinterp.3 \
	ns_tclappendint.3 ns_tcldeallocateinterp.3 \
	ns_tcldestroyinterp.3 ns_tclenterset.3 ns_tcleval.3 \
	ns_tclfreeset.3 ns_tclgetconn.3 \
	ns_tclgetopenchannel.3 ns_tclgetopenfd.3 \
	ns_tclgetset.3 ns_tclgetset2.3 ns_tclinitinterps.3 \
	ns_tclinitmodule.3 ns_tclinterpserver.3 \
	ns_tcllibrary.3 ns_tcllogerror.3 \
	ns_tclmarkfordelete.3 ns_tclregisteratcreate.3 \
	ns_tclregisterdeferred.3 ns_threadcreate.3 \
	ns_threadexit.3 ns_threadfree.3 ns_threadgetname.3 \
	ns_threadid.3 ns_threadjoin.3 ns_threadmalloc.3 \
	ns_threadpool.3 ns_threadrealloc.3 ns_threadself.3 \
	ns_threadsetname.3 ns_threadyield.3 \
	ns_timedwaitforevent.3 ns_tlsalloc.3 ns_tlsget.3 \
	ns_tlsset.3 ns_unlockmutex.3 \
	ns_unregisterproxyrequest.3 ns_unregisterrequest.3 \
	ns_unscheduleproc.3 ns_urlisdir.3 ns_urlisfile.3 \
	ns_urlspecificalloc.3 ns_urlspecificdestroy.3 \
	ns_urlspecificget.3 ns_urlspecificgetexact.3 \
	ns_urlspecificset.3 ns_urltofile.3 \
	ns_utimedwaitforevent.3 ns_waitforevent.3 \
	ns_waitforprocess.3 ns_waitforsemaphore.3 \
	ns_waitforstartup.3 ns_waitforthread.3 \
	ns_waitprocess.3 ns_waitthread.3 ns_writeconn.3 \
	ns_writelockrwlock.3 ns_writeunlockrwlock.3 \

MANN=	ns_adp_abort.n ns_adp_argc.n ns_adp_argv.n \
	ns_adp_bind_args.n ns_adp_break.n ns_adp_debug.n ns_adp_dir.n \
	ns_adp_dump.n ns_adp_eval.n ns_adp_exception.n \
	ns_adp_include.n ns_adp_parse.n ns_adp_puts.n \
	ns_adp_registertag.n ns_adp_return.n ns_adp_stream.n \
	ns_adp_tell.n ns_adp_trunc.n ns_atclose.n ns_atexit.n \
	ns_atshutdown.n ns_atsignal.n ns_cache_flush.n \
	ns_cache_names.n ns_cache_size.n ns_cache_stats.n \
	ns_checkurl.n ns_chmod.n ns_cond.n ns_config.n \
	ns_configsection.n ns_configsections.n ns_conn.n \
	ns_conncptofp.n ns_connsendfp.n ns_cp.n ns_cpfp.n ns_cport.n \
	ns_critsec.n ns_crypt.n ns_db.n ns_dbconfigpath.n ns_dberror.n \
	ns_dbformvalue.n ns_dbformvalueput.n ns_dbquotename.n \
	ns_dbquotevalue.n ns_deleterow.n ns_eval.n ns_event.n ns_ext.n \
	ns_findrowbyid.n ns_fmttime.n ns_ftruncate.n \
	ns_get_multipart_formdata.n ns_getcsv.n ns_getform.n \
	ns_geturl.n ns_gifsize.n ns_gmtime.n ns_guesstype.n \
	ns_hostbyaddr.n ns_hrefs.n ns_httpget.n ns_httpopen.n \
	ns_httptime.n ns_info.n ns_insertrow.n ns_jpegsize.n ns_kill.n \
	ns_library.n ns_link.n ns_localsqltimestamp.n ns_localtime.n \
	ns_log.n ns_logroll.n ns_markfordelete.n ns_menu.n ns_mkdir.n \
	ns_mktemp.n ns_modlog.n ns_modlogcontrol.n ns_modulepath.n \
	ns_mutex.n ns_normalizepath.n ns_param.n ns_parseheader.n \
	ns_parsehttptime.n ns_parsequery.n ns_passwordcheck.n \
	ns_perm.n ns_permpasswd.n ns_pooldescription.n \
	ns_queryexists.n ns_queryget.n ns_querygetall.n ns_quotehtml.n \
	ns_rand.n ns_register_adptag.n ns_register_filter.n \
	ns_register_proc.n ns_register_trace.n ns_rename.n \
	ns_requestauthorize.n ns_respond.n ns_return.n ns_rmdir.n \
	ns_rollfile.n ns_rwlock.n ns_schedule_daily.n \
	ns_schedule_proc.n ns_schedule_weekly.n ns_section.n ns_sema.n \
	ns_sendmail.n ns_server.n ns_set.n ns_set_precision.n \
	ns_setexpires.n ns_share.n ns_shutdown.n ns_sleep.n \
	ns_sockaccept.n ns_sockblocking.n ns_sockcallback.n \
	ns_sockcheck.n ns_socketpair.n ns_socklisten.n \
	ns_socklistencallback.n ns_socknonblocking.n ns_socknread.n \
	ns_sockopen.n ns_sockselect.n ns_striphtml.n ns_symlink.n \
	ns_thread.n ns_time.n ns_tmpnam.n ns_truncate.n ns_unlink.n \
	ns_unregister_proc.n ns_unschedule_proc.n ns_url2file.n \
	ns_urldecode.n ns_urlencode.n ns_uudecode.n ns_uuencode.n \
	ns_write.n ns_writecontent.n ns_writefp.n

# AOLServer's `make install' actually installs into ${WRKSRC}/root,
# so we have to do this by hand.  Just as well---it gives us a
# chance to respect hier(7). :-)

post-install:
# Binaries
.for prog in nsd76 nsd82
	${INSTALL_PROGRAM} ${WRKSRC}/root/bin/${prog} ${PREFIX}/sbin
.endfor
	${LN} -sf ${PREFIX}/sbin/nsd82 ${PREFIX}/sbin/nsd
.for prog in translate-ini translate-tcl
	${INSTALL_SCRIPT} ${WRKSRC}/root/bin/${prog} ${PREFIX}/sbin
.endfor

# Loadable modules
	${MKDIR} ${PREFIX}/libexec/aolserver
	${INSTALL_DATA} ${WRKSRC}/root/bin/*.so	${PREFIX}/libexec/aolserver

# Headers
# nsd.h is needed for, e.g., building the Postgres driver
	${MKDIR} ${PREFIX}/include/aolserver
.for header in root/include/*.h nsd/nsd.h
	${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/aolserver
.endfor

# Libraries
	${INSTALL_DATA} ${WRKSRC}/root/lib/libnspd.a ${PREFIX}/lib

# Man pages
	${INSTALL_MAN} ${WRKSRC}/doc/man3/* ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/mann/* ${PREFIX}/man/mann

# Other documentation
	${MKDIR} ${PREFIX}/share/doc/aolserver
.for doc in doc/asem.html doc/urlspace.txt CHANGES.b5 CHANGES.b6 INSTALL README README.NSV
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/aolserver
.endfor

# Server root, or something
	${MKDIR} ${PREFIX}/www/aolserver/servers/server1
	${INSTALL_DATA} ${WRKSRC}/root/nsd.tcl ${PREFIX}/www/aolserver/nsd.tcl.sample
	${TAR} -C ${WRKSRC}/root -c -f - modules | ${TAR} -C ${PREFIX}/www/aolserver -x -f -
	${TAR} -C ${WRKSRC}/root/servers/server1 -c -f - . | ${TAR} -C ${PREFIX}/www/aolserver/servers/server1 -x -f -
	${CHOWN} nobody.nogroup ${PREFIX}/www/aolserver/servers/server1/modules/nslog

# Server log
	${MKDIR} ${PREFIX}/www/aolserver/log
	${CHOWN} nobody.nogroup ${PREFIX}/www/aolserver/log

# Examples
	${MKDIR} ${PREFIX}/share/examples/aolserver
	${TAR} -C ${WRKSRC}/examples -c -f - . | ${TAR} -C ${PREFIX}/share/examples/aolserver -x -f -

# Startup file
	@if [ ! -f ${PREFIX}/etc/rc.d/aolserver.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/aolserver.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/aolserver.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/nsd  ] && ${PREFIX}/sbin/nsd -u nobody -t ${PREFIX}/www/aolserver/nsd.tcl && ${ECHO} -n ' aolserver'" >> ${PREFIX}/etc/rc.d/aolserver.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/aolserver.sh; \
	fi
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
