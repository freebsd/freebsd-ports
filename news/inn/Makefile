# Created by: torstenb
# $FreeBSD$

PORTNAME?=	inn
PORTVERSION?=	2.5.4
PORTREVISION?=	2
CATEGORIES=	news ipv6
# Master distribution broken
MASTER_SITES?=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR?=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	InterNetNews -- the Internet meets Netnews

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RC_SUBR=	innd
SUB_FILES=	pkg-install

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USES=		gmake perl5 uidfix

CONFLICTS?=	inn-stable-[0-9]* inn-current-[0-9]*

OPTIONS_DEFINE=		KERBEROS SASL KEYWORDS BERKELEYDB OPENSSL \
			TAGGED_HASH LARGE_FILES GNUPG
OPTIONS_DEFAULT=	KEYWORDS
OPTIONS_SUB=		yes

KERBEROS_DESC=		Enable Kerberos v5 (for auth_krb5)
SASL_DESC=		Enable SASL (for imapfeed authentication)
TAGGED_HASH_DESC=	Use tagged hash table for history
LARGE_FILES_DESC=	Support for files larger than 2GB
KEYWORDS_DESC=		Automatic keyword generation support
BERKELEYDB_DESC=	Enable BerkeleyDB (for ovdb overview method)
OPENSSL_DESC=		Enable OpenSSL (for NNTP over TLS/SSL support)
GNUPG_DESC=		GnuPG support (for pgpverify control message)

VARBASE?=	/var

.include "Makefile.layout"

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		ac_cv_prog_AWK="${AWK}"
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man		\
			--prefix=${INN_NEWSBASE}		\
			--with-spool-dir=${INN_NEWSSPOOL}	\
			--with-log-dir=${INN_LOGDIR}		\
			--with-tmp-dir=${INN_TMPDIR}		\
			--sysconfdir=${INN_CONFDIR}		\
			--with-run-dir=${INN_RUNDIR}		\
			--with-db-dir=${INN_DBDIR}		\
			--datarootdir=${INN_SHAREDIR}		\
			--enable-ipv6 --with-perl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBERKELEYDB}
USE_BDB=		44+
CONFIGURE_ENV+=		DB_VER=db${BDB_VER}
CONFIGURE_ENV+=		DB_LIB=${BDB_LIB_NAME}
CONFIGURE_ARGS+=	--with-berkeleydb=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MKERBEROS}
.    if exists(${LOCALBASE}/bin/krb5-config)
LIB_DEPENDS+=		libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-kerberos=${LOCALBASE}
.    else
CONFIGURE_ARGS+=	--with-kerberos=/usr
.    endif
CONFIGURE_ENV+=		ac_cv_search_krb5_parse_name="-lcrypt -lcrypto -lkrb5 -lasn1 -lroken -lhx509"
CONFIGURE_ENV+=		ac_cv_func_krb5_init_ets=yes
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

.if ${PORT_OPTIONS:MLARGE_FILES}
CONFIGURE_ARGS+=	--enable-largefiles
.    if ${PORT_OPTIONS:MTAGGED_HASH}
IGNORE=			cannot be compiled with both LARGE_FILES and TAGGED_HASH: please re-run make config
.    endif
.endif

.if ${PORT_OPTIONS:MKEYWORDS}
CONFIGURE_ARGS+=	--enable-keywords
.endif

.if ${PORT_OPTIONS:MSASL}
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
LIB_DEPENDS+=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.endif

.if ${PORT_OPTIONS:MTAGGED_HASH}
CONFIGURE_ARGS+=	--enable-tagged-hash
DBZ_FILES=		dir pag
PLIST_SUB+=		WITH_TAGGED_HASH=""
PLIST_SUB+=		WITHOUT_TAGGED_HASH="@comment "
.else
DBZ_FILES=		dir hash index
PLIST_SUB+=		WITH_TAGGED_HASH="@comment "
PLIST_SUB+=		WITHOUT_TAGGED_HASH=""
.endif
SUB_LIST+=		DBZ_FILES="${DBZ_FILES}"

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MGNUPG}
# Although pgpverify needs gpgv/gpgv2,
# checking 'gpg' is the shortest way to check any version of GnuPG installed.
BUILD_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
.endif

PORTDOCS=	CONTRIBUTORS HACKING INSTALL LICENSE MANIFEST NEWS README TODO
HEADERS=	clibrary.h config.h dbz.h libinn.h storage.h


TO_BE_STRIPPED=	bin/auth/resolv/domain bin/auth/resolv/ident \
		bin/auth/passwd/ckpasswd bin/auth/passwd/radius bin/rnews.libexec/decode \
		bin/rnews.libexec/encode bin/tdx-util bin/innd bin/nnrpd \
		bin/innfeed bin/imapfeed bin/buffindexed_d bin/convdate bin/expire \
		bin/expireover bin/fastrm bin/grephistory bin/makedbz bin/makehistory \
		bin/prunehistory bin/ctlinnd bin/getlist bin/inews bin/innconfval \
		bin/ovdb_init bin/ovdb_monitor bin/ovdb_server bin/ovdb_stat bin/rnews \
		bin/sm bin/actsync bin/archive bin/batcher bin/buffchan bin/cvtbatch \
		bin/filechan bin/inndf bin/innxmit bin/innxbatch bin/ninpaths bin/nntpget \
		bin/overchan bin/shlock bin/shrinkfile bin/tinyleaf

CONFIG_FILES=	actsync.cfg actsync.ign buffindexed.conf control.ctl \
		control.ctl.local cycbuff.conf \
		distrib.pats distributions \
		expire.ctl localgroups incoming.conf inn.conf innfeed.conf \
		innreport.conf innshellvars.local innshellvars.pl.local innshellvars.tcl.local \
		innwatch.ctl moderators news2mail.cf \
		newsfeeds nocem.ctl \
		nnrpd.track nntpsend.ctl ovdb.conf \
		passwd.nntp readers.conf send-uucp.cf \
		storage.conf subscriptions

SUB_LIST+=	EGDIR="${EXAMPLESDIR:C,^${PREFIX},\\$\\${PREFIX},}"
PLIST_SUB+=	ETCFILES="${CONFIG_FILES}"

.include <bsd.port.pre.mk>

.if !defined(GID)
GID!=	id -g
.endif

post-patch:
	@${REINPLACE_CMD} -E 's!\$$[{(]PATHETC[})]!${EXAMPLESDIR}!g' \
	                  ${WRKSRC}/site/Makefile
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
#	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${STAGEDIR}${INN_DBDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${EXAMPLESDIR}/db
	@${REINPLACE_CMD} -e '/^RUNASUSER	*=/s/news/${UID}/'	\
		-e '/^RUNASGROUP	*=/s/news/${GID}/'	\
		-e '/^RNEWSGROUP	*=/s/news/${GID}/'	\
		${WRKSRC}/Makefile.global

post-build:
	@${FIND} ${WRKSRC} -name "inn.conf" \
	    | ${XARGS} ${REINPLACE_CMD} -e 's/^pathhost:.*/pathhost:               host.example.com/'

post-install:
.for FILE in ${TO_BE_STRIPPED}
	${STRIP_CMD} ${STAGEDIR}${INN_NEWSBASE}/${FILE}
.endfor
	${MKDIR} ${STAGEDIR}${INN_NEWSSPOOL}
	${MKDIR} ${STAGEDIR}${INN_CONFDIR}
.for FILE in ${CONFIG_FILES}
	${CP} -p ${STAGEDIR}${EXAMPLESDIR}/${FILE} ${STAGEDIR}${INN_CONFDIR}/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${INN_DBDIR}
.for FILE in active active.times newsgroups
	${MV} ${STAGEDIR}${INN_DBDIR}/${FILE} \
		${STAGEDIR}${INN_DBDIR}/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
