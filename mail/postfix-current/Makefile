PORTNAME=	postfix
DISTVERSION=	3.11-20250818
PORTREVISION?=	0
PORTEPOCH=	6
CATEGORIES=	mail
MASTER_SITES=	https://postfix-mirror.horus-it.com/postfix-release/ \
		http://ftp.porcupine.org/mirrors/postfix-release/ \
		http://de.postfix.org/ftpmirror/ \
		http://www.artfiles.org/postfix.org/postfix-release/ \
		http://mirror.lhsolutions.nl/postfix-release/ \
		ftp://postfix.mirrors.pair.com/
MASTER_SITES:=	${MASTER_SITES:S|$|experimental/|}
PKGNAMESUFFIX=	-current
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Experimental Postfix version ${COMMENT_${FLAVOR}}
WWW=		https://www.postfix.org/

LICENSE=	EPL IPL10
LICENSE_COMB=	multi
LICENSE_NAME_IPL10=	IBM PUBLIC LICENSE VERSION 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS_IPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FLAVORS=			default ldap mongo mysql pgsql sasl sqlite
default_CONFLICTS_INSTALL=	postfix-current-base-ldap postfix-current-base-sasl \
				postfix-current-ldap postfix-current-sasl \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sqlite postfix-current-base-sqlite
ldap_PKGNAMESUFFIX=		-current-ldap
ldap_CONFLICTS_INSTALL=		postfix-current postfix-current-base \
				postfix-current-base-sasl postfix-current-sasl \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sqlite postfix-current-base-sqlite
mongo_PKGNAMESUFFIX=		-current-mongo
mongo_CONFLICTS_INSTALL=	postfix-current postfix-current-base \
				postfix-current-ldap postfix-current-base-ldap \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sasl postfix-current-base-sasl \
				postfix-current-sqlite postfix-current-base-sqlite
mysql_PKGNAMESUFFIX=		-current-mysql
mysql_CONFLICTS_INSTALL=	postfix-current postfix-current-base \
				postfix-current-ldap postfix-current-base-ldap \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sasl postfix-current-base-sasl \
				postfix-current-sqlite postfix-current-base-sqlite
pgsql_PKGNAMESUFFIX=		-current-pgsql
pgsql_CONFLICTS_INSTALL=	postfix-current postfix-current-base \
				postfix-current-ldap postfix-current-base-ldap \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-sasl postfix-current-base-sasl \
				postfix-current-sqlite postfix-current-base-sqlite
sasl_PKGNAMESUFFIX=		-current-sasl
sasl_CONFLICTS_INSTALL=		postfix-current postfix-current-base \
				postfix-current-base-ldap postfix-current-ldap \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sqlite postfix-current-base-sqlite
sqlite_PKGNAMESUFFIX=		-current-sqlite
sqlite_CONFLICTS_INSTALL=	postfix-current postfix-current-base \
				postfix-current-ldap postfix-current-base-ldap \
				postfix-current-mongo postfix-current-base-mongo \
				postfix-current-mysql postfix-current-base-mysql \
				postfix-current-pgsql postfix-current-base-pgsql \
				postfix-current-sasl postfix-current-base-sasl

COMMENT_ldap=	(with OpenLDAP support)
COMMENT_sasl=	(with Cyrus SASL support)

USES=		cpe shebangfix ssl
USE_RC_SUBR=	postfix
USE_SUBMAKE=	yes

SHEBANG_FILES=	auxiliary/qshape/qshape.pl

SCRIPTS_ENV+=	POSTFIX_DEFAULT_MTA="${POSTFIX_DEFAULT_MTA}"

CONFLICTS_INSTALL=	courier-0.* opensmtpd opensmtpd-devel \
			postfix postfix-base postfix-ldap-sasl \
			postfix-sasl postfix35 sendmail \
			sendmail-devel

USERS=		postfix
GROUPS=		mail maildrop postfix

OPTIONS_DEFINE=		BDB BLACKLISTD CDB DOCS EAI INST_BASE LDAP LMDB MONGO \
			MYSQL NIS PCRE2 PGSQL SASL SQLITE TEST TLS TLSRPT
OPTIONS_DEFAULT?=	BLACKLISTD EAI PCRE2 TLS
OPTIONS_RADIO=		RG1
OPTIONS_RADIO_RG1=	SASLKMIT SASLKRB5
.if ${FLAVOR:U} == ldap
OPTIONS_SLAVE=		LDAP
.elif ${FLAVOR:U} == sasl
OPTIONS_SLAVE=		SASL
.endif
.if !empty(FLAVOR) && ${FLAVOR:U} != default
OPTIONS_FILE=	${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options
.endif
OPTIONS_SUB=		yes

BLACKLISTD_DESC=	Enable blacklistd support
CDB_DESC=		CDB maps lookups
EAI_DESC=		Email Address Internationalization (SMTPUTF8) support
INST_BASE_DESC=		Install into /usr and /etc/postfix
LDAP_DESC=		LDAP maps (uses WITH_OPENLDAP_VER)
LMDB_DESC=		LMDB maps
PCRE2_DESC=		Use Perl Compatible Regular Expressions, version 2
RG1_DESC=		Kerberos network authentication protocol type
SASLKMIT_DESC=		If your SASL req. MIT Kerberos5, select this
SASLKRB5_DESC=		If your SASL req. Kerberos5, select this
SASL_DESC=		Cyrus SASL support (Dovecot SASL is always built in)
TEST_DESC=		SMTP/LMTP test server and generator
TLSRPT_DESC=		Enable sending RFC 8460 TLS reports

BDB_USES=			bdb
BLACKLISTD_EXTRA_PATCHES=	${FILESDIR}/extra-patch-blacklistd
CDB_LIB_DEPENDS=		libcdb.so:databases/tinycdb
EAI_LIB_DEPENDS=		libicuuc.so:devel/icu
LDAP_USES=			ldap
LMDB_LIB_DEPENDS=		liblmdb.so:databases/lmdb
MONGO_LIB_DEPENDS=		libbson-1.0.so:devel/libbson \
				libmongoc-1.0.so:devel/mongo-c-driver
MYSQL_USES?=			mysql
PCRE2_LIB_DEPENDS=		libpcre2-8.so:devel/pcre2
PGSQL_USES=			pgsql
SASLKMIT_LIB_DEPENDS=		libkrb5.so:security/krb5
SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
SQLITE_USES=			sqlite
TLSRPT_LIB_DEPENDS=		libtlsrpt.so:mail/libtlsrpt

ALL_TARGET=	default

.include <bsd.port.options.mk>

HTML1=		body_checks.5.html bounce.5.html postfix-power.png \
		scache.8.html tlsmgr.8.html

STRIP_LIBEXEC=	anvil bounce cleanup discard dnsblog error flush lmtp local \
		master nqmgr oqmgr pickup pipe postlogd postscreen proxymap \
		qmgr qmqpd scache showq smtp smtpd spawn tlsmgr tlsproxy \
		trivial-rewrite verify virtual

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

MAKEFILEFLAGS+=	pie=yes CC="${CC}" OPT="${CFLAGS}"

.if defined(TLS) && ${SSL_DEFAULT} == libressl
BROKEN=		error: OpenSSL-1.1.1 is the minimum supported version. LibreSSL is not supported
.endif

.if ${PORT_OPTIONS:MINST_BASE}
.if ${FLAVOR:U} == ldap
PKGNAMESUFFIX=	-current-base-ldap
.elif ${FLAVOR:U} == sasl
PKGNAMESUFFIX=	-current-base-sasl
.else
PKGNAMESUFFIX=	-current-base
.endif
PREFIX=		/usr
ETCDIR=		/etc/postfix
.endif

PLIST_SUB+=	PFETC=${ETCDIR}

# check if mailwrapper supports $LOCALBASE
.if ${OPSYS} == FreeBSD
SUB_LIST+=	MC_PREFIX="${LOCALBASE}" \
		USE_LOCALBASE_MAILER_CONF="yes"
.else
SUB_LIST+=	MC_PREFIX="" \
		USE_LOCALBASE_MAILER_CONF="no"
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
READMEDIR=	${DOCSDIR}
.else
READMEDIR=	no
.endif

# dynamic direcory location
DAEMONDIR=		${PREFIX}/libexec/postfix
SHLIB_DIRECTORY=	${PREFIX}/lib/postfix
# new proposed location is ETCDIR (see README_FILES/INSTALL)
# keep compatiblity with Postfix 2.6 .. 2.11 and use DAEMOMDIR
META_DIRECTORY=		${DAEMONDIR}

SUB_LIST+=	REQUIRE="${_REQUIRE}"
SUB_FILES+=	mailer.conf.postfix pkg-install pkg-message

POSTFIX_CCARGS+=	-DDEF_CONFIG_DIR=\\\"${ETCDIR}\\\" \
			-DDEF_DAEMON_DIR=\\\"${DAEMONDIR}\\\" \
			-DDEF_META_DIR=\\\"${META_DIRECTORY}\\\" \
			-DDEF_COMMAND_DIR=\\\"${PREFIX}/sbin\\\" \
			-DDEF_SENDMAIL_PATH=\\\"${PREFIX}/sbin/sendmail\\\" \
			-DDEF_NEWALIAS_PATH=\\\"${PREFIX}/bin/newaliases\\\" \
			-DDEF_MAILQ_PATH=\\\"${PREFIX}/bin/mailq\\\" \
			-DDEF_MANPAGE_DIR=\\\"${PREFIX}/share/man\\\" \
			-DDEF_README_DIR=\\\"${READMEDIR}\\\" \
			-DDEF_HTML_DIR=\\\"${READMEDIR}\\\" \
			-DDEF_QUEUE_DIR=\\\"/var/spool/postfix\\\" \
			-DDEF_DATA_DIR=\\\"/var/db/postfix\\\" \
			-DDEF_MAIL_OWNER=\\\"postfix\\\" \
			-DDEF_SGID_GROUP=\\\"maildrop\\\" \
			-Wmissing-prototypes -Wformat -Wno-comment

# Default requirement for postfix rc script
_REQUIRE=	LOGIN cleanvar dovecot

# always build with Dovecot SASL support, Cyrus is optional
# see Postfix HISTORY 20051222
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH

# Email Address Internationalization (EAI, RFC 6531..6533)
.if ${PORT_OPTIONS:MEAI}
POSTFIX_CCARGS+=	-DHAS_EAI -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -licuuc
.else
POSTFIX_CCARGS+=	-DNO_EAI
.endif

.if ${PORT_OPTIONS:MPCRE2}
DYN_EXT+=		pcre
POSTFIX_CCARGS+=	-DHAS_PCRE=2 -I${LOCALBASE}/include
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_PCRE=`${LOCALBASE}/bin/pcre2-config --libs8`"
.else
POSTFIX_CCARGS+=	-DNO_PCRE
.endif

.if ${PORT_OPTIONS:MSASL}
POSTFIX_CCARGS+=	-DUSE_CYRUS_SASL -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/sasl
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lsasl2 -lpam -lcrypt
.else
POSTFIX_CCARGS+=	-DDEF_SERVER_SASL_TYPE=\\\"dovecot\\\"
.endif

.if ${PORT_OPTIONS:MSASLKRB5}
POSTFIX_AUXLIBS+=	-lkrb5 -lhx509 -lcrypto -lcrypt -lcom_err -lasn1 \
			-lroken
.endif

.if ${PORT_OPTIONS:MSASLKMIT}
POSTFIX_AUXLIBS+=	-Wl,--rpath,$${KRB5_HOME:-${LOCALBASE}}/lib -lkrb5 \
			-lcrypto -lcrypt -lcom_err
.endif

.if ${PORT_OPTIONS:MTLS}
POSTFIX_CCARGS+=	-DUSE_TLS -I${OPENSSLINC}
# XXX LDFLAGS possible breaks dynamic building
POSTFIX_AUXLIBS+=	-L${OPENSSLLIB} ${LDFLAGS} -lssl -lcrypto
.else
POSTFIX_CCARGS+=	-DNO_TLS
.endif

.if ${PORT_OPTIONS:MTLSRPT}
POSTFIX_CCARGS+=	-DUSE_TLSRPT -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib -ltlsrpt
.endif

.if ${PORT_OPTIONS:MBDB}
POSTFIX_CCARGS+=	-I${BDB_INCLUDE_DIR}
POSTFIX_AUXLIBS+=	-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}
.endif

.if ${PORT_OPTIONS:MBLACKLISTD}
. if ${OPSYS} == FreeBSD
POSTFIX_AUXLIBS+=	-lblacklist
. else
IGNORE=		blacklistd is only supported on FreeBSD
. endif
.endif

.if ${PORT_OPTIONS:MMONGO}
DYN_EXT+=		mongodb
POSTFIX_CCARGS+=	-DHAS_MONGODB -I${LOCALBASE}/include/libmongoc-1.0 \
			-I${LOCALBASE}/include/libbson-1.0
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_MONGODB=-L${LOCALBASE}/lib -lmongoc-1.0 -lbson-1.0"
.endif

.if ${PORT_OPTIONS:MMYSQL}
DYN_EXT+=		mysql
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_MYSQL=-L${LOCALBASE}/lib/mysql -lmysqlclient -lz -lm"
_REQUIRE+=		mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
DYN_EXT+=		pgsql
POSTFIX_CCARGS+=	-DHAS_PGSQL -I${LOCALBASE}/include
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_PGSQL=-L${LOCALBASE}/lib -lpq"
_REQUIRE+=		postgresql
.endif

.if ${PORT_OPTIONS:MSQLITE}
DYN_EXT+=		sqlite
POSTFIX_CCARGS+=	-DHAS_SQLITE -I${LOCALBASE}/include
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_SQLITE=-L${LOCALBASE}/lib -lsqlite3 -lpthread"
.endif

.if ${PORT_OPTIONS:MLDAP}
DYN_EXT+=		ldap
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/sasl -DUSE_LDAP_SASL
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_LDAP=-L${LOCALBASE}/lib -lldap -llber"
_REQUIRE+=		slapd
.endif

.if ${PORT_OPTIONS:MCDB}
DYN_EXT+=		cdb
POSTFIX_CCARGS+=	-DHAS_CDB -I${LOCALBASE}/include
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_CDB=-L${LOCALBASE}/lib -lcdb"
.endif

.if ${PORT_OPTIONS:MNIS}
POSTFIX_CCARGS+=	-DHAS_NIS
_REQUIRE+=		ypserv
.endif

.if ${PORT_OPTIONS:MTEST}
BINTEST=	qmqp-sink qmqp-source smtp-sink smtp-source
MANTEST=	qmqp-sink.1 qmqp-source.1 smtp-sink.1 smtp-source.1
.endif

.if ${PORT_OPTIONS:MLMDB}
DYN_EXT+=		lmdb
POSTFIX_CCARGS+=	-DHAS_LMDB -I${LOCALBASE}/include
POSTFIX_DYN_AUXLIBS+=	"AUXLIBS_LMDB=-L${LOCALBASE}/lib -llmdb"
.endif

# sed script for files in ${WRKSRC}/README_FILES ${WRKSRC}/conf ${WRKSRC}/man
REINPLACE=	s!^PATH=.*!PATH=/bin:/sbin:/usr/bin:/usr/sbin:${PREFIX}/bin:${PREFIX}/sbin!;\
		s!(_directory = )/usr/!\1${PREFIX}/!g;\
		s!^(data_directory = /var/)lib/!\1db/!g;\
		s!^\#(mynetworks_style = host)!\1!g;\
		s!^(sendmail_path =)!\1 ${PREFIX}/sbin/sendmail!g;\
		s!^(newaliases_path =)!\1 ${PREFIX}/bin/newaliases!g;\
		s!^(mailq_path =)!\1 ${PREFIX}/bin/mailq!g;\
		s!^(setgid_group =)!\1 maildrop!g;\
		s!^(manpage_directory =)!\1 ${PREFIX}/share/man!g;\
		s!^((html|readme)_directory =)!\1 ${READMEDIR}!g;\
		\!^\#alias_database = dbm:/etc/mail/aliases$$!d;\
		s!(:|= )/etc/postfix!\1$$config_directory!g;\
		s!/etc/postfix!${ETCDIR}!g;\
		s!^(sample_directory =)!\1 ${ETCDIR}!g; \
		s!($$config_directory/(access|aliases|canonical|generic|header_checks|relocated|transport|virtual):f:root:-:644:)p1!\1o!;

post-patch:
.if ${PORT_OPTIONS:MSASL} && ! ${PORT_OPTIONS:MMYSQL} && exists(${LOCALBASE}/lib/libsasl2.a)
	@if /usr/bin/nm ${LOCALBASE}/lib/libsasl2.a | ${GREP} -wq "mysql_init"; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "Your SASL library is compiled with MYSQL"; \
		${ECHO_MSG} "If you use MYSQL in ${PORTNAME} consider CTRL+C and"; \
		${ECHO_MSG} "select MYSQL OPTION in config menu."; \
		${ECHO_MSG} "# make clean config"; \
		${ECHO_MSG}; \
		sleep 5; \
	fi
.endif

	@${ECHO_CMD} '<HTML><BODY>See <A HREF="header_checks.5.html">header_checks.5.html</A></BODY></HTML>' \
		> ${WRKSRC}/html/body_checks.5.html
	@${REINPLACE_CMD} -E -e 's!^(#define DEF_SGID_GROUP[^"]+)"postdrop"$$!\1"maildrop"!' \
		${WRKSRC}/src/global/mail_params.h
	@${FIND} -X ${WRKSRC}/README_FILES ${WRKSRC}/conf ${WRKSRC}/man \
		-type f -a ! \( -name INSTALL -o -name aliases \) | ${XARGS} \
		${REINPLACE_CMD} -i '' -E -e '${REINPLACE}'

.for f in ${HTML1}
	@${ECHO_CMD} '$$html_directory/$f:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
.endfor
	@${ECHO_CMD} '$$manpage_directory/man1/posttls-finger.1:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
	@${ECHO_CMD} '$$command_directory/posttls-finger:f:root:-:755' \
		>> ${WRKSRC}/conf/postfix-files

do-configure:
	${MAKE} -C ${WRKSRC} -f Makefile.init makefiles \
	${MAKEFILEFLAGS} CCARGS="${POSTFIX_CCARGS}" \
	shared=yes shlib_directory=${SHLIB_DIRECTORY} \
	dynamicmaps=yes \
	${POSTFIX_DYN_AUXLIBS} \
	AUXLIBS="${POSTFIX_AUXLIBS}"

pre-install-INST_BASE-on:
	${MKDIR} ${STAGEDIR}/etc/rc.d

do-install:
	${MAKE} -C ${WRKSRC} non-interactive-package \
		install_root=${STAGEDIR} tempdir=${WRKDIR} \
		shlib_directory=${SHLIB_DIRECTORY} \
		config_directory=${ETCDIR} \
		command_directory=${PREFIX}/sbin \
		daemon_directory=${DAEMONDIR} \
		meta_directory=${META_DIRECTORY} \
		html_directory=${READMEDIR} \
		mailq_path=${PREFIX}/bin/mailq \
		manpage_directory=${PREFIX}/share/man \
		newaliases_path=${PREFIX}/bin/newaliases \
		readme_directory=${READMEDIR} \
		sendmail_path=${PREFIX}/sbin/sendmail

	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/rmail/rmail ${STAGEDIR}${PREFIX}/bin/rmail
	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl ${STAGEDIR}${PREFIX}/bin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 ${STAGEDIR}${PREFIX}/share/man/man1

# == do not overwrite existing config
	${MV} ${STAGEDIR}${ETCDIR}/main.cf ${STAGEDIR}${ETCDIR}/main.cf.sample
	${MV} ${STAGEDIR}${ETCDIR}/master.cf ${STAGEDIR}${ETCDIR}/master.cf.sample
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${STAGEDIR}${DATADIR}
.for SAMPLEFILE in access aliases canonical generic header_checks relocated transport virtual
	${MV} ${STAGEDIR}${ETCDIR}/${SAMPLEFILE} ${STAGEDIR}${ETCDIR}/${SAMPLEFILE}.sample
.endfor

# == chop dynamicmaps.cf entries into dedicated .cf files
# for future sub-packages support
.for f in ${DYN_EXT}
# adjust dynamicmaps.cf
	${GREP} -e "^#" -e "^${f}" ${STAGEDIR}${META_DIRECTORY}/dynamicmaps.cf \
		> ${STAGEDIR}${META_DIRECTORY}/dynamicmaps.cf.d/${f}.cf && \
		${SED} -i '' -e '/${f}/d' ${STAGEDIR}${META_DIRECTORY}/dynamicmaps.cf

# adjust / generate postfix-files for dynamic modules
	${SED} -i '' -e '/postfix-${f}.so/d' ${STAGEDIR}${META_DIRECTORY}/postfix-files && \
	${PRINTF} '# Do not edit this file.\
		\n$$shlib_directory/postfix-${f}.so:f:root:-:755\
		\n$$meta_directory/postfix-files.d/${f}-files:f:root:-:644\
		\n$$meta_directory/dynamicmaps.cf.d/${f}.cf:f:root:-:644\n' \
		> ${STAGEDIR}${META_DIRECTORY}/postfix-files.d/${f}-files
.endfor

# Fix compressed man pages and strip executables
	${SED} -i '' -E -e "s|(man[158]/.*.[158]):|\1.gz:|g" ${STAGEDIR}${META_DIRECTORY}/postfix-files
	-@${STRIP_CMD} ${STRIP_LIBEXEC:S|^|${STAGEDIR}${DAEMONDIR}/|}
	-@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	-@${STRIP_CMD} ${STAGEDIR}${SHLIB_DIRECTORY}/*.so

do-install-TEST-on:
	${INSTALL_PROGRAM} ${BINTEST:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MANTEST:S|^|${WRKSRC}/man/man1/|} ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
