# Created by: torstenb
# $FreeBSD$

PORTNAME=	inn
PORTVERSION=	2.6.1
CATEGORIES=	news
MASTER_SITES=	ISC/${PORTNAME}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	InterNetNews -- the Internet meets Netnews

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RC_SUBR=	innd
SUB_FILES=	pkg-install

USES=		cpe gmake libtool perl5 uidfix
CPE_VENDOR=	isc

CONFLICTS?=	inn-stable-[0-9]* inn-current-[0-9]*

OPTIONS_DEFINE=		BERKELEYDB GNUPG KERBEROS SASL KEYWORDS \
			LARGE_FILES OPENSSL SETGID_INEWS TAGGED_HASH \
			UUCP_RNEWS DOCS EXAMPLES
OPTIONS_DEFAULT=	BERKELEYDB GNUPG KEYWORDS OPENSSL LARGE_FILES \
			SETGID_INEW UUCP_RNEWS
OPTIONS_SUB=		yes

KERBEROS_DESC=		Enable Kerberos v5 (for auth_krb5)
SASL_DESC=		Enable SASL (for imapfeed authentication)
TAGGED_HASH_DESC=	Use tagged hash table for history
LARGE_FILES_DESC=	Support for files larger than 2GB
KEYWORDS_DESC=		Automatic keyword generation support
BERKELEYDB_DESC=	Enable BerkeleyDB (for ovdb overview method)
OPENSSL_DESC=		Enable OpenSSL (for NNTP over TLS/SSL support)
GNUPG_DESC=		GnuPG support (for pgpverify control message)
UUCP_RNEWS_DESC=	Install rnews suitable for use with net/freebsd-uucp
SETGID_INEWS_DESC=	Enable posting articles locally for all users

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
			--with-perl

UUCP_RNEWS_CONFIGURE_ON=--enable-uucp-rnews
UUCP_RNEWS_RUN_DEPENDS=	uucp:net/freebsd-uucp

INNLIB_LONG=		4.0.0
LIBVER_LONG=		3.0.1
PLIST_SUB+=		LIBVER=${LIBVER_LONG:R:R} LIBVER_LONG=${LIBVER_LONG} \
			INNLIB=${INNLIB_LONG:R:R} INNLIB_LONG=${INNLIB_LONG}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBERKELEYDB}
USES+=			bdb
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE} \
			--with-bdb-lib=${LOCALBASE}/lib \
			--with-bdb-include=${BDB_INCLUDE_DIR}
.endif

.if ${PORT_OPTIONS:MKERBEROS}
.    if exists(${LOCALBASE}/bin/krb5-config)
LIB_DEPENDS+=		libgssapi_krb5.so:security/krb5
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.    else
CONFIGURE_ARGS+=	--with-krb5=/usr
.    endif
CONFIGURE_ENV+=		ac_cv_search_krb5_parse_name="-lcrypt -lcrypto -lkrb5 -lasn1 -lroken -lhx509"
CONFIGURE_ENV+=		ac_cv_func_krb5_init_ets=yes
.else
CONFIGURE_ARGS+=	--without-krb5
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
LIB_DEPENDS+=		libsasl2.so:security/cyrus-sasl2
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
USES+=		ssl
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MGNUPG}
# Although pgpverify needs gpgv/gpgv2,
# checking 'gpg' is the shortest way to check any version of GnuPG installed.
BUILD_DEPENDS+=		gpg:security/gnupg
RUN_DEPENDS+=		gpg:security/gnupg
.endif

.if ${PORT_OPTIONS:MSETGID_INEWS}
PLIST_SUB+=		MODE_INEWS="2555"
.else
PLIST_SUB+=		MODE_INEWS=""
.endif
PORTDOCS=	CONTRIBUTORS HACKING INSTALL LICENSE MANIFEST NEWS README TODO

TO_BE_STRIPPED=	bin/actsync bin/archive bin/auth/passwd/auth_krb5 \
	bin/auth/passwd/ckpasswd bin/auth/passwd/radius bin/auth/resolv/domain \
	bin/auth/resolv/ident bin/batcher bin/buffchan bin/buffindexed_d \
	bin/convdate bin/ctlinnd bin/cvtbatch bin/expire bin/expireover \
	bin/fastrm bin/filechan bin/getlist bin/grephistory bin/imapfeed \
	bin/inews bin/innbind bin/innconfval bin/innd bin/inndf bin/innfeed \
	bin/innxbatch bin/innxmit bin/makedbz bin/makehistory bin/ninpaths \
	bin/nnrpd bin/nntpget bin/ovdb_init bin/ovdb_monitor bin/ovdb_server \
	bin/ovdb_stat bin/overchan bin/prunehistory bin/rnews \
	bin/rnews.libexec/decode bin/rnews.libexec/encode bin/shlock \
	bin/shrinkfile bin/sm bin/tdx-util bin/tinyleaf \
	lib/libinn.so.${INNLIB_LONG} lib/libinnhist.so.${LIBVER_LONG} \
	lib/libstorage.so.${LIBVER_LONG}

CONFIG_FILES=	actsync.cfg actsync.ign buffindexed.conf control.ctl \
	control.ctl.local cycbuff.conf distrib.pats distributions expire.ctl \
	localgroups incoming.conf inn.conf innfeed.conf innreport.conf \
	innshellvars.local innshellvars.pl.local innshellvars.tcl.local \
	innwatch.ctl moderators news2mail.cf newsfeeds nocem.ctl nnrpd.track \
	nntpsend.ctl ovdb.conf passwd.nntp readers.conf send-uucp.cf \
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
	                  ${WRKSRC}/configure ${WRKSRC}/authprogs/auth_krb5.c
	@${REINPLACE_CMD} -e '/^#pragma/d' ${WRKSRC}/*/*.c
.if ${PORT_OPTIONS:MBERKELEYDB}
	@${REINPLACE_CMD} -e 's!-ldb!-ldb-${BDB_VER}!' ${WRKSRC}/configure
.endif
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
	-${TEST} -f ${STAGEDIR}${INN_NEWSBASE}/${FILE} && \
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
