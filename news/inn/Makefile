PORTNAME?=	inn
PORTVERSION?=	2.7.3
PORTREVISION?=	1
CATEGORIES=	news
MASTER_SITES=	ISC
MASTER_SITE_SUBDIR?=	${PORTNAME}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	InterNetNews -- the Internet meets Netnews
WWW=		https://www.eyrie.org/~eagle/software/inn/

LICENSE=	GPLv2 ISCL
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gmake libtool perl5 uidfix
CPE_VENDOR=	isc
USE_RC_SUBR=	innd

.ifnmake portclippy
VARBASE?=	/var
.endif

.include "Makefile.layout"

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${INN_NEWSBASE}
# Point to base system mailwrapper to avoid configure failure in jails
CONFIGURE_ARGS+=	--datarootdir=${INN_SHAREDIR} \
			--sysconfdir=${INN_CONFDIR} \
			--with-db-dir=${INN_DBDIR} \
			--with-log-dir=${INN_LOGDIR} \
			--with-perl \
			--with-run-dir=${INN_RUNDIR} \
			--with-sendmail=/usr/sbin/sendmail \
			--with-spool-dir=${INN_NEWSSPOOL} \
			--with-tmp-dir=${INN_TMPDIR}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		ac_cv_prog_AWK="${AWK}"

CONFLICTS?=	inn-current

SUB_FILES=	pkg-install
SUB_LIST+=	EGDIR="${EXAMPLESDIR:C,^${PREFIX},\\$\\${PREFIX},}"

INNLIB_LONG?=		9.0.2
LIBVER_LONG?=		3.0.9
LIBSTORAGEVER_LONG?=	3.1.3

CONFIG_FILES+=	actsync.cfg actsync.ign buffindexed.conf control.ctl \
		control.ctl.local cycbuff.conf distrib.pats distributions \
		expire.ctl inn-radius.conf inn-secrets.conf incoming.conf \
		inn.conf innfeed.conf innreport.conf innshellvars.local \
		innshellvars.pl.local innshellvars.tcl.local innwatch.ctl \
		localgroups moderators news2mail.cf newsfeeds nocem.ctl \
		nnrpd.track nntpsend.ctl ovdb.conf passwd.nntp readers.conf \
		send-uucp.cf storage.conf subscriptions

.if ${BRANCH:U} == 2.8
PLIST_SUB+=	SNAPSHOT=""
.else
PLIST_SUB+=	SNAPSHOT="@comment "
.endif
PLIST_SUB+=	ETCFILES="${CONFIG_FILES}" \
		INNLIB=${INNLIB_LONG:R:R} \
		INNLIB_LONG=${INNLIB_LONG} \
		LIBSTORAGEVER=${LIBSTORAGEVER_LONG:R:R} \
		LIBSTORAGEVER_LONG=${LIBSTORAGEVER_LONG} \
		LIBVER=${LIBVER_LONG:R:R} \
		LIBVER_LONG=${LIBVER_LONG}
PORTDOCS=	CONTRIBUTORS HACKING INSTALL LICENSE MANIFEST NEWS README TODO

OPTIONS_DEFINE=		BERKELEYDB BLOCKLISTD DOCS EXAMPLES GNUPG KERBEROS \
			KEYWORDS LARGE_FILES OPENSSL PYTHON SASL SETGID_INEWS \
			SQLITE TAGGED_HASH UUCP_RNEWS
OPTIONS_DEFAULT=	BERKELEYDB BLOCKLISTD GNUPG KEYWORDS LARGE_FILES \
			OPENSSL PYTHON SETGID_INEWS SQLITE UUCP_RNEWS
.if ${BRANCH:U} == 2.8
OPTIONS_DEFINE+=	EXPERIMENTAL
.endif
OPTIONS_SUB=		yes

BERKELEYDB_DESC=	Enable BerkeleyDB (for ovdb overview method)
BLOCKLISTD_DESC=	Enable blocklistd support
EXPERIMENTAL_DESC=	Experimental upstream patches (ovsqlite, bloom filter)
GNUPG_DESC=		GnuPG support (for pgpverify control message)
KERBEROS_DESC=		Enable Kerberos v5 (for auth_krb5)
KEYWORDS_DESC=		Automatic keyword generation support
LARGE_FILES_DESC=	Support for files larger than 2GB
OPENSSL_DESC=		Enable OpenSSL (for NNTP over TLS/SSL support)
PYTHON_DESC=		Enable support for embedded Python
SASL_DESC=		Enable SASL (for imapfeed authentication)
SETGID_INEWS_DESC=	Enable posting articles locally for all users
SQLITE_DESC=		Enable SQLite (for ovsqlite overview method)
TAGGED_HASH_DESC=	Use tagged hash table for history
UUCP_RNEWS_DESC=	Install rnews suitable for use with net/freebsd-uucp

BERKELEYDB_USES=		bdb
BERKELEYDB_CONFIGURE_ON=	--with-bdb-include=${BDB_INCLUDE_DIR} \
				--with-bdb-lib=${LOCALBASE}/lib \
				--with-bdb=${LOCALBASE}

.if ${BRANCH:U} == 2.8 && ${OSVERSION:U} >= 1500000
BLOCKLISTD_CONFIGURE_WITH=	blocklist
.else
BLOCKLISTD_CONFIGURE_WITH=	blacklist
.endif

# Although pgpverify needs gpgv/gpgv2,
# checking 'gpg' is the shortest way to check any version of GnuPG installed.
GNUPG_BUILD_DEPENDS=	gpg:security/gnupg
GNUPG_RUN_DEPENDS=	gpg:security/gnupg

KERBEROS_USES=		gssapi
KERBEROS_CONFIGURE_ON=	--with-krb5=${GSSAPIBASEDIR}
KERBEROS_CONFIGURE_OFF=	--without-krb5

KEYWORDS_CONFIGURE_ENABLE=	keywords

LARGE_FILES_PREVENTS=		TAGGED_HASH
LARGE_FILES_PREVENTS_MSG=	cannot be compiled with both LARGE_FILES and \
				TAGGED_HASH
LARGE_FILES_CONFIGURE_ENABLE=	largefiles

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}

PYTHON_USES=		gettext-runtime python
PYTHON_CONFIGURE_ON=	--with-python

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}

SETGID_INEWS_CONFIGURE_ENABLE=	setgid-inews
SETGID_INEWS_PLIST_SUB=		MODE_INEWS="2555"
SETGID_INEWS_PLIST_SUB_OFF=	MODE_INEWS=""

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--without-sqlite3
SQLITE_VARS=		CONFIG_FILES+=ovsqlite.conf

TAGGED_HASH_CONFIGURE_ENABLE=	tagged-hash
TAGGED_HASH_SUB_LIST=		DBZ_FILES="dir pag"
TAGGED_HASH_SUB_LIST_OFF=	DBZ_FILES="dir hash index"
TAGGED_HASH_PLIST_SUB=		WITH_TAGGED_HASH="" \
				WITHOUT_TAGGED_HASH="@comment "
TAGGED_HASH_PLIST_SUB_OFF=	WITH_TAGGED_HASH="@comment " \
				WITHOUT_TAGGED_HASH=""

UUCP_RNEWS_RUN_DEPENDS=		uucp:net/freebsd-uucp
UUCP_RNEWS_CONFIGURE_ENABLE=	uucp-rnews

EXPERIMENTAL_PATCH_SITES=	https://github.com/InterNetNews/inn/commit/
EXPERIMENTAL_PATCHFILES=	cf4a8ecac2f3149505f9a55cdd95383e9b3f725b.patch:-p1 \
				0d84255b417c89219225f0a034fd4c068d9749a0.patch:-p1 \
				05d70a17c5720be25fcd957c8ab7a0c12a64d30b.patch:-p1 \
				0b308fdd3f6255e8c81a3deaf1bad08cb1fe8f1d.patch:-p1 \
				755ab163eb124658959a8e4168732e6a7f7dc300.patch:-p1 \
				d23b3f84aebe3fb49af0b42b7cfaa7a7ebae5a26.patch:-p1 \
				919cf653b54c72ef4bf1563f3fb6bbdf9a193a3a.patch:-p1 \
				93a36682f7ba9d013d07859882c2b8c501da249e.patch:-p1 \
				d0c379ee3f325f4a80dada6c3129c23496b1c83e.patch:-p1
EXPERIMENTAL_PLIST_SUB=		EXPERIMENTAL=""
EXPERIMENTAL_PLIST_SUB_OFF=	EXPERIMENTAL="@comment "

.include <bsd.port.pre.mk>

GID?=		${.MAKE.GID}

post-extract-EXPERIMENTAL-on:
	@${CP} ${PKGDIR}/files/gitignore ${WRKSRC}/.gitignore

post-patch:
	@${REINPLACE_CMD} -E 's!\$$[{(]PATHETC[})]!${EXAMPLESDIR}!g' \
	                  ${WRKSRC}/site/Makefile
.if ${PORT_OPTIONS:MBERKELEYDB}
	@${REINPLACE_CMD} -e 's!-ldb!-ldb-${BDB_VER}!' ${WRKSRC}/configure
.endif
.if ${BRANCH:U} == 2.8
.  if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
	@${FIND} ${WRKSRC} -type f -exec ${SED} -i '' \
		-e 's/BLOCKLIST/BLACKLIST/g' \
		-e 's/Blocklist/Blacklist/g' \
		-e 's/blocklist/blacklist/g' {} +
.  endif
.else
.  if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
	@${FIND} ${WRKSRC} -type f -exec ${SED} -i '' \
		-e 's/BLACKLIST/BLOCKLIST/g' \
		-e 's/Blacklist/Blocklist/g' \
		-e 's/blacklist/blocklist/g' {} +
.  endif
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${INN_DBDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${EXAMPLESDIR}/db
	@${REINPLACE_CMD} -e '/^RUNASUSER	*=/s/=.*/=	${UID}/'	\
		-e '/^RUNASGROUP	*=/s/=.*/=	${GID}/'	\
		-e '/^RNEWSGROUP	*=/s/=.*/=	${GID}/'	\
		${WRKSRC}/Makefile.global

post-build:
	@${FIND} ${WRKSRC} -name "inn.conf" \
	    | ${XARGS} ${REINPLACE_CMD} -e 's/^pathhost:.*/pathhost:               host.example.com/'

post-install:
	${FIND} ${STAGEDIR}${INN_NEWSBASE} -type f \
	    \( -perm +111 -o -name '*.so.*' \) ! -name '*.a' \
	    -exec ${STRIP_CMD} {} + 2>/dev/null || ${TRUE}
	${MKDIR} ${STAGEDIR}${INN_NEWSSPOOL}
	${MKDIR} ${STAGEDIR}${INN_CONFDIR}
.for FILE in ${CONFIG_FILES}
	${CP} -p ${STAGEDIR}${EXAMPLESDIR}/${FILE} ${STAGEDIR}${INN_CONFDIR}/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${INN_DBDIR}
.for FILE in active active.times history newsgroups
	${MV} ${STAGEDIR}${INN_DBDIR}/${FILE} \
		${STAGEDIR}${INN_DBDIR}/${FILE}.sample
.endfor
	${TOUCH} ${STAGEDIR}${INN_DBDIR}/history.dir.sample
.if ${PORT_OPTIONS:MTAGGED_HASH}
	${TOUCH} ${STAGEDIR}${INN_DBDIR}/history.pag.sample
.else
	${TOUCH} ${STAGEDIR}${INN_DBDIR}/history.hash.sample
	${TOUCH} ${STAGEDIR}${INN_DBDIR}/history.index.sample
.endif
.for FILE in filter_innd.pl filter_innd.py filter_nnrpd.pl nnrpd_access.pl \
	nnrpd_access.py nnrpd_auth.pl nnrpd_auth.py nnrpd_dynamic.py \
	startup_innd.pl
	${MV} ${STAGEDIR}${INN_NEWSBASE}/bin/filter/${FILE} \
		${STAGEDIR}${INN_NEWSBASE}/bin/filter/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
