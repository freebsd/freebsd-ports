# New ports collection makefile for:	inn
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1), 14 Feb 1999 (2.2)
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME?=	inn
PORTVERSION?=	2.4.6
PORTREVISION?=	0
CATEGORIES=	news ipv6
MASTER_SITES?=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR?=	${PORTNAME}

MAINTAINER=	Fluffy@fluffy.khv.ru
COMMENT=	InterNetNews -- the Internet meets Netnews

USE_RC_SUBR=	innd.sh
SUB_FILES=	pkg-install

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_GMAKE=	yes
USE_OPENSSL=	yes
WANT_PERL=	yes

CONFLICTS?=	inn-stable-[0-9]* inn-current-[0-9]*

BRANCH?=	# Empty

OPTIONS=	PERL		"Embedded Perl script support"			On	\
		PYTHON		"Embedded Python module support"		Off	\
		TCL		"Embedded TCL support"				Off	\
		KERBEROS	"Enable Kerberos auth support"			Off	\
		SASL		"Enable SASL support (for imapfeed auth)"	Off	\
		TAGGED_HASH	"Use tagged hash table for history"		Off	\
		LARGE_FILES	"Support for files larger than 2GB"		Off	\
		KEYWORDS	"Automatic keyword generation support"		On	\
		BERKELEYDB	"Enable BerkeleyDB (for ovdb overview method)"	Off

VARBASE?=	/var

.include "Makefile.layout"

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man		\
			--prefix=${INN_NEWSBASE}		\
			--with-spool-dir=${INN_NEWSSPOOL}	\
			--with-log-dir=${INN_LOGDIR}		\
			--with-tmp-dir=${INN_TMPDIR}		\
			--with-openssl=${OPENSSLBASE}		\
			--with-etc-dir=${INN_ETCDIR}		\
			--with-run-dir=${INN_RUNDIR}		\
			--with-db-dir=${INN_DBDIR}		\
			--with-ssl=${OPENSSLBASE}		\
			--enable-ipv6

.include <bsd.port.options.mk>

.if defined(WITH_BERKELEYDB)
USE_BDB=		44+
CONFIGURE_ENV+=		DB_VER=db${BDB_VER}
CONFIGURE_ENV+=		DB_LIB=${BDB_LIB_NAME}
CONFIGURE_ARGS+=	--with-berkeleydb=${LOCALBASE}
.endif

.if defined(WITH_KERBEROS)
.    if exists(${LOCALBASE}/bin/krb5-config)
LIB_DEPENDS+=		gssapi_krb5:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-kerberos=${LOCALBASE}
.    else
CONFIGURE_ARGS+=	--with-kerberos=/usr
.    endif
CONFIGURE_ENV+=		ac_cv_search_krb5_parse_name="-lcrypt -lcrypto -lkrb5 -lasn1 -lroken -lhx509"
CONFIGURE_ENV+=		ac_cv_func_krb5_init_ets=yes
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

.if !defined(WITHOUT_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		YES
CONFIGURE_ARGS+=	--with-python
.    include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(WITH_TCL)
USE_TCL=		84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}
.endif

.if defined(WITH_MAXSOCKET)
CONFIGURE_ARGS+=	--with-max-sockets=${WITH_MAXSOCKET}
.endif

.if defined(WITH_LARGE_FILES)
CONFIGURE_ARGS+=	--enable-largefiles
.    if defined(WITH_TAGGED_HASH)
IGNORE=			cannot be compiled with both LARGE_FILES and TAGGED_HASH: please re-run make config
.    endif
.endif

.if !defined(WITHOUT_KEYWORDS)
CONFIGURE_ARGS+=	--enable-keywords
.endif

.if defined(WITH_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif

.if defined(WITH_TAGGED_HASH)
CONFIGURE_ARGS+=	--enable-tagged-hash
DBZ_FILES=		dir pag
PLIST_SUB+=		WITH_TAGGED_HASH=""
PLIST_SUB+=		WITHOUT_TAGGED_HASH="@comment "
.else
CONFIGURE_ARGS+=	--enable-largefiles
DBZ_FILES=		dir hash index
PLIST_SUB+=		WITH_TAGGED_HASH="@comment "
PLIST_SUB+=		WITHOUT_TAGGED_HASH=""
.endif

PORTDOCS=	CONTRIBUTORS HACKING INSTALL LICENSE MANIFEST NEWS README TODO
HEADERS=	clibrary.h config.h dbz.h

MAN1=		convdate.1 fastrm.1 getlist.1 grephistory.1 inews.1 innconfval.1 \
		innfeed.1 innmail.1 nntpget.1 pgpverify.1 rnews.1 shlock.1 \
		shrinkfile.1 simpleftp.1 sm.1 pullnews.1
MAN3=		clientlib.3 dbz.3 inndcomm.3 libauth.3 libinn.3 libinnhist.3 \
		libstorage.3 list.3 qio.3 tst.3 uwildmat.3
MAN5=		active.5 active.times.5 buffindexed.conf.5 control.ctl.5 \
		cycbuff.conf.5 distrib.pats.5 expire.ctl.5 history.5 incoming.conf.5 \
		inn.conf.5 innfeed.conf.5 innwatch.ctl.5 moderators.5 motd.news.5 \
		newsfeeds.5 newslog.5 nnrpd.track.5 nntpsend.ctl.5 ovdb.5 \
		overview.fmt.5 passwd.nntp.5 radius.conf.5 readers.conf.5 \
		storage.conf.5 subscriptions.5
MAN8=		actsync.8 archive.8 auth_smb.8 batcher.8 buffchan.8 \
		ckpasswd.8 cnfsheadconf.8 cnfsstat.8 controlchan.8 ctlinnd.8 \
		cvtbatch.8 domain.8 expire.8 expireover.8 expirerm.8 filechan.8 \
		ident.8 inncheck.8 innd.8 inndf.8 innreport.8 innstat.8 \
		innupgrade.8 innwatch.8 innxbatch.8 innxmit.8 mailpost.8 makedbz.8 \
		makehistory.8 mod-active.8 news.daily.8 news2mail.8 ninpaths.8 \
		nnrpd.8 nntpsend.8 ovdb_init.8 ovdb_monitor.8 ovdb_server.8 \
		ovdb_stat.8 overchan.8 perl-nocem.8 prunehistory.8 \
		radius.8 rc.news.8 scanlogs.8 send-nntp.8 send-uucp.8 sendinpaths.8 \
		tally.control.8 tdx-util.8 writelog.8

.if defined(WITH_KERBEROS)
MAN8+=		auth_krb5.8
.endif

TO_BE_STRIPPED=	bin/auth/resolv/domain bin/auth/resolv/ident bin/auth/passwd/auth_smb \
		bin/auth/passwd/ckpasswd bin/auth/passwd/radius bin/rnews.libexec/decode \
		bin/rnews.libexec/encode bin/tdx-util bin/innd bin/nnrpd \
		bin/innfeed bin/imapfeed bin/convdate bin/expire \
		bin/expireover bin/fastrm bin/grephistory bin/makedbz bin/makehistory \
		bin/prunehistory bin/ctlinnd bin/getlist bin/inews bin/innconfval \
		bin/ovdb_init bin/ovdb_monitor bin/ovdb_server bin/ovdb_stat bin/rnews \
		bin/sm bin/actsync bin/archive bin/batcher bin/buffchan bin/cvtbatch \
		bin/filechan bin/inndf bin/innxmit bin/innxbatch bin/ninpaths bin/nntpget \
		bin/overchan bin/shlock bin/shrinkfile

CONFIG_FILES=	actsync.cfg actsync.ign buffindexed.conf control.ctl cycbuff.conf \
		distrib.pats expire.ctl incoming.conf inn.conf innfeed.conf \
		innreport.conf innwatch.ctl moderators motd.news news2mail.cf \
		newsfeeds nnrpd.track nntpsend.ctl ovdb.conf overview.fmt \
		passwd.nntp radius.conf readers.conf sasl.conf storage.conf \
		subscriptions

.if ${BRANCH} != "current"
MAN1+=		startinnfeed.1
MAN3+=		parsedate.3
MAN5+=		sasl.conf.5
MAN8+=		actsyncd.8 inndstart.8
TO_BE_STRIPPED+=bin/inndstart bin/startinnfeed
HEADERS+=	libinn.h storage.h
PLIST_SUB+=	NOTCURRENT=""
.else
PLIST_SUB+=	NOTCURRENT="@comment "
MAN8+=		innbind.8 tinyleaf.8
.endif

SUB_LIST+=	EGDIR="${EXAMPLESDIR:C,^${PREFIX},\\$\\${PREFIX},}"
PLIST_SUB+=	ETCFILES="${CONFIG_FILES}"

post-patch:
	@${REINPLACE_CMD} -E 's!\$$[{(]PATHETC[})]!${EXAMPLESDIR}!g' \
	                  ${WRKSRC}/site/Makefile
.if defined(WITH_TCL)
	@${REINPLACE_CMD} -e 's!<tcl.h>!<tcl8.4/tcl.h>!' ${WRKSRC}/innd/innd.h
	@${REINPLACE_CMD} -e 's!-ltcl!-ltcl84!'			\
	                  ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's!et/com_err\.h!com_err.h!g'	\
	                  -e 's!-lk5crypto!!g'			\
	                  ${WRKSRC}/configure
	@${ECHO_CMD} '/^$$D$$(PATH_HISTORY)' >  ${WRKDIR}/ex.script
	@${ECHO_CMD} '+'                     >> ${WRKDIR}/ex.script
	@${ECHO_CMD} 'mark t'                >> ${WRKDIR}/ex.script
	@${ECHO_CMD} '/^$$'                  >> ${WRKDIR}/ex.script
	@${ECHO_CMD} "'t, d"                 >> ${WRKDIR}/ex.script
	@${ECHO_CMD} 'wq!'                   >> ${WRKDIR}/ex.script
	@cd ${WRKDIR} && ex ${WRKSRC}/site/Makefile < ex.script > /dev/null

pre-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-build:
	@${FIND} ${WRKSRC} -name "inn.conf" \
	    | ${XARGS} ${REINPLACE_CMD} -e 's/^pathhost:.*/pathhost:               host.example.com/'

post-install:
.if !defined(WITHOUT_STRIP)
.    for FILE in ${TO_BE_STRIPPED}
	[ -e ${INN_NEWSBASE}/${FILE} ] && ${STRIP_CMD} ${INN_NEWSBASE}/${FILE}
.    endfor
.endif
	${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man ${PREFIX}/man/man1 ${PREFIX}/man/man3 \
		${PREFIX}/man/man5 ${PREFIX}/man/man8
	${MKDIR} ${INN_NEWSSPOOL}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.    for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.    endfor
.endif
	${MKDIR} ${INN_NEWSBASE}/include
.for FILE in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/${FILE} ${INN_NEWSBASE}/include/
.endfor
	${CHOWN} ${BINOWN}:news ${INN_NEWSBASE}/bin/auth/passwd/ckpasswd
	${CHMOD} 4755 ${INN_NEWSBASE}/bin/auth/passwd/ckpasswd
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} CHECK-CONF ${INN_ETCDIR}
	@(if [ ! -f ${INN_DBDIR}/history ] ; then \
	    ${ECHO} 'Creating empty history database...' ; \
	    cd ${INN_DBDIR} ; \
	    ${TOUCH} history ; \
	    ${CHMOD} 644 history ; \
	    ${CHOWN} news:news history ; \
	    su -fm news -c "${INN_NEWSBASE}/bin/makedbz -i" ; \
	    for s in ${DBZ_FILES}  ; do \
	        ${MV} history.n.$${s} history.$${s} ; \
	    done ; \
	fi)
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL PORTMODE

.include <bsd.port.mk>
