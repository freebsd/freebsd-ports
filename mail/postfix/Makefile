# Created by: Torsten Blum <torstenb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postfix
PORTVERSION=	2.11.7
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/ \
		http://de.postfix.org/ftpmirror/ \
		http://cdn.postfix.johnriley.me/mirrors/postfix-release/ \
		http://www.artfiles.org/postfix.org/postfix-release/ \
		http://mirror.lhsolutions.nl/postfix-release/ \
		ftp://postfix.mirrors.pair.com/
MASTER_SITES:=	${MASTER_SITES:S|$|official/|}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Secure alternative to widely-used Sendmail

LICENSE=	IPL10
LICENSE_NAME=	IBM PUBLIC LICENSE VERSION 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PORTSCOUT=	limit:^2\.11\.

VDAVERSION=	2.10.0
CONFLICTS_INSTALL?=	courier-0.* opensmtpd-[0-9]* \
		postfix2?-* postfix210-* postfix-3.* \
		postfix-current-[23].* postfix-current-base-[23].* \
		sendmail-8.* sendmail+*-8.* smail-3.* zmailer-2.*

USERS=		postfix
GROUPS=		mail maildrop postfix
USES=		perl5 shebangfix cpe
SHEBANG_LANG=	perl
SHEBANG_FILES=	auxiliary/qshape/qshape.pl

USE_RC_SUBR=	postfix
USE_SUBMAKE=	yes
USE_PERL5=	build
SCRIPTS_ENV+=	POSTFIX_DEFAULT_MTA="${POSTFIX_DEFAULT_MTA}"

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BDB CDB DOCS INST_BASE LDAP LDAP_SASL LMDB MYSQL \
		NIS PCRE PGSQL SASL SPF SQLITE TEST TLS VDA

OPTIONS_RADIO=		RG1 RG2
OPTIONS_RADIO_RG1=	DOVECOT DOVECOT2
OPTIONS_RADIO_RG2=	SASLKRB5 SASLKMIT
OPTIONS_DEFAULT=	PCRE TLS

BDB_USE=		BDB=yes
CDB_LIB_DEPENDS=	libcdb.so:${PORTSDIR}/databases/tinycdb
LDAP_USE=		OPENLDAP=yes
LMDB_LIB_DEPENDS=	liblmdb.so:${PORTSDIR}/databases/lmdb
MYSQL_USE=		MYSQL=yes
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PGSQL_USES=		pgsql
SASLKMIT_LIB_DEPENDS=	libkrb5.so:${PORTSDIR}/security/krb5
SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
SPF_LIB_DEPENDS=	libspf2.so:${PORTSDIR}/mail/libspf2
SQLITE_USE=		SQLITE=yes
TLS_USE=		OPENSSL=yes

CDB_DESC=	CDB maps lookups
INST_BASE_DESC=	Install into /usr and /etc/postfix
LDAP_DESC=	LDAP maps (uses WITH_OPENLDAP_VER)
LDAP_SASL_DESC=	LDAP client-to-server SASL auth
LMDB_DESC=	LMDB maps
SPF_DESC=	SPF support (via libspf2 1.2.x)
TEST_DESC=	SMTP/LMTP test server and generator
VDA_DESC=	VDA (Virtual Delivery Agent)

RG1_DESC=	Dovecot SASL authentication methods
DOVECOT_DESC=	Dovecot 1.x SASL authentication method
DOVECOT2_DESC=	Dovecot 2.x SASL authentication method
RG2_DESC=	Kerberos network authentication protocol type
SASLKRB5_DESC=	If your SASL req. Kerberos5, select this
SASLKMIT_DESC=	If your SASL req. MIT Kerberos5, select this

.include <bsd.port.options.mk>

HTML1=	body_checks.5.html bounce.5.html postfix-power.png \
	scache.8.html tlsmgr.8.html

STRIP_LIBEXEC=	anvil bounce cleanup discard dnsblog error flush lmtp local master \
		nqmgr oqmgr pickup pipe postscreen proxymap qmgr qmqpd scache showq \
		smtp smtpd spawn tlsmgr tlsproxy trivial-rewrite verify virtual

.if !defined(BATCH) && !defined(PACKAGE_BUILDING) && exists(/etc/mail/mailer.conf)
OLD_MAILER!=	${GREP} -m 1 '^purgestat' /etc/mail/mailer.conf || ${ECHO_CMD}
.if !empty(OLD_MAILER)
IS_INTERACTIVE=	yes
.endif
.endif

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

MAKEFILEFLAGS+=	CC="${CC}" OPT="${CFLAGS}"

.if ${PORT_OPTIONS:MINST_BASE}
PKGNAMESUFFIX=	-base
PREFIX=		/usr
ETCDIR=		/etc/postfix
PLIST_SUB+=	BMAN="share/"
.else
PLIST_SUB+=	BMAN=""
.endif

PLIST_SUB+=	PFETC=${ETCDIR}

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
READMEDIR=	${DOCSDIR}
.else
READMEDIR=	no
.endif

DAEMONDIR=	${PREFIX}/libexec/postfix

SUB_LIST+=	REQUIRE="${_REQUIRE}" READMEDIR="${READMEDIR}" \
		DAEMONDIR="${DAEMONDIR}"
SUB_FILES+=	pkg-install pkg-message

POSTFIX_CCARGS+=	-DDEF_CONFIG_DIR=\\\"${ETCDIR}\\\" \
			-DDEF_DAEMON_DIR=\\\"${DAEMONDIR}\\\" \
			-DDEF_COMMAND_DIR=\\\"${PREFIX}/sbin\\\" \
			-DDEF_SENDMAIL_PATH=\\\"${PREFIX}/sbin/sendmail\\\" \
			-DDEF_NEWALIAS_PATH=\\\"${PREFIX}/bin/newaliases\\\" \
			-DDEF_MAILQ_PATH=\\\"${PREFIX}/bin/mailq\\\" \
			-DDEF_MANPAGE_DIR=\\\"${MANPREFIX}/man\\\" \
			-DDEF_README_DIR=\\\"${READMEDIR}\\\" \
			-DDEF_HTML_DIR=\\\"${READMEDIR}\\\" \
			-DDEF_QUEUE_DIR=\\\"/var/spool/postfix\\\" \
			-DDEF_DATA_DIR=\\\"/var/db/postfix\\\" \
			-DDEF_MAIL_OWNER=\\\"postfix\\\" \
			-DDEF_SGID_GROUP=\\\"maildrop\\\" \
			-Wmissing-prototypes -Wformat -Wno-comment

# Default requirement for postfix rc script
_REQUIRE=		LOGIN cleanvar

.if ${PORT_OPTIONS:MPCRE}
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lpcre
.else
POSTFIX_CCARGS+=	-DNO_PCRE
.endif

.if ${PORT_OPTIONS:MSASL}
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -DUSE_CYRUS_SASL -I${LOCALBASE}/include -I${LOCALBASE}/include/sasl
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lsasl2 -lpam -lcrypt
.endif

.if ${PORT_OPTIONS:MDOVECOT} || ${PORT_OPTIONS:MDOVECOT2}
.if ${PORT_OPTIONS:MDOVECOT}
RUN_DEPENDS+=		dovecot:${PORTSDIR}/mail/dovecot
.else
RUN_DEPENDS+=		dovecot:${PORTSDIR}/mail/dovecot2
.endif
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -DDEF_SERVER_SASL_TYPE=\\\"dovecot\\\"
_REQUIRE+=		dovecot
.endif

.if ${PORT_OPTIONS:MSASLKRB5}
POSTFIX_AUXLIBS+=	-lkrb5 -lhx509 -lcrypto -lcrypt -lcom_err -lasn1 -lroken
.endif

.if ${PORT_OPTIONS:MSASLKMIT}
POSTFIX_AUXLIBS+=	-Wl,--rpath,$${KRB5_HOME:-${LOCALBASE}}/lib -lkrb5 -lcrypto -lcrypt -lcom_err
.endif

.if ${PORT_OPTIONS:MTLS}
POSTFIX_CCARGS+=	-DUSE_TLS -I${OPENSSLINC}
POSTFIX_AUXLIBS+=	-L${OPENSSLLIB} ${LDFLAGS} -lssl -lcrypto
.else
POSTFIX_CCARGS+=	-DNO_TLS
.endif

.if ${PORT_OPTIONS:MSPF}
PATCH_SITES+=		LOCAL/mm
PATCHFILES+=		postfix-2.8.0-libspf2-1.2.x-0.patch.gz
PATCH_DIST_STRIP=	-p1
POSTFIX_CCARGS+=	-DHAVE_NS_TYPE -DHAS_SPF -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lspf2
.endif

.if ${PORT_OPTIONS:MBDB}
INVALID_BDB_VER=	6
POSTFIX_CCARGS+=	-I${BDB_INCLUDE_DIR}
POSTFIX_AUXLIBS+=	-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}
.endif

.if ${PORT_OPTIONS:MMYSQL}
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lz -lcrypt -lm
_REQUIRE+=		mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
POSTFIX_CCARGS+=	-DHAS_PGSQL -I${LOCALBASE}/include -I${LOCALBASE}/pgsql/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/pgsql/lib -lpq -lcrypt
_REQUIRE+=		postgresql
.endif

.if ${PORT_OPTIONS:MSQLITE}
POSTFIX_CCARGS+=	-DHAS_SQLITE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lsqlite3
.endif

.if ${PORT_OPTIONS:MLDAP}
. if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
. endif
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lldap -llber
_REQUIRE+=		slapd
. if ${PORT_OPTIONS:MLDAP_SASL}
.  if ! ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.  endif
WANT_OPENLDAP_SASL=	yes
POSTFIX_CCARGS+=	-I${LOCALBASE}/include/sasl -DUSE_LDAP_SASL
. endif
.endif

.if ${PORT_OPTIONS:MCDB}
POSTFIX_CCARGS+=	-DHAS_CDB -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lcdb
.endif

.if ${PORT_OPTIONS:MNIS}
POSTFIX_CCARGS+=	-DHAS_NIS
_REQUIRE+=		ypserv
.endif

.if ${PORT_OPTIONS:MVDA}
PATCH_SITES+=		http://vda.sourceforge.net/VDA/:vda
PATCHFILES+=		postfix-vda-v13-${VDAVERSION}.patch:vda
PATCH_DIST_STRIP=	-p1
.endif

.if ${PORT_OPTIONS:MTEST}
BINTEST=	qmqp-sink qmqp-source smtp-sink smtp-source
MANTEST=	qmqp-sink.1 qmqp-source.1 smtp-sink.1 smtp-source.1
.endif

.if ${PORT_OPTIONS:MLMDB}
POSTFIX_CCARGS+=	-DHAS_LMDB -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -llmdb
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
		s!^(manpage_directory =)!\1 ${MANPREFIX}/man!g;\
		s!^((html|readme)_directory =)!\1 ${READMEDIR}!g;\
		\!^\#alias_database = dbm:/etc/mail/aliases$$!d;\
		s!(:|= )/etc/postfix!\1$$config_directory!g;\
		s!/etc/postfix!${ETCDIR}!g;\
		s!^(sample_directory =)!\1 ${ETCDIR}!g;\
		s!($config_directory/(access|aliases|canonical|generic|header_checks|relocated|transport|virtual):f:root:-:644:)p1!\1o!;

pre-patch:
.if ${PORT_OPTIONS:MSASL} && ! ${PORT_OPTIONS:MMYSQL} && exists(${LOCALBASE}/lib/libsasl2.a)
	@if /usr/bin/nm ${LOCALBASE}/lib/libsasl2.a | ${GREP} -wq "mysql_init"; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "Your SASL library it's compiled with MYSQL"; \
		${ECHO_MSG} "If you use MYSQL in ${PORTNAME} consider CTRL+C and"; \
		${ECHO_MSG} "select MYSQL OPTION in config menu."; \
		${ECHO_MSG} "# make clean config"; \
		${ECHO_MSG}; \
		sleep 5; \
	fi
.endif

	@${ECHO} '<HTML><BODY>See <A HREF="header_checks.5.html">header_checks.5.html</A></BODY></HTML>' \
		> ${WRKSRC}/html/body_checks.5.html
	@${REINPLACE_CMD} -E -e 's![[:<:]]perl[[:>:]]!${PERL}!' \
		${WRKSRC}/src/bounce/Makefile.in
	@${REINPLACE_CMD} -E -e 's!^(#define DEF_SGID_GROUP[^"]+)"postdrop"$$!\1"maildrop"!' \
		${WRKSRC}/src/global/mail_params.h
	@${FIND} -X ${WRKSRC}/README_FILES ${WRKSRC}/conf ${WRKSRC}/man \
		-type f -a ! \( -name INSTALL -o -name aliases \) | ${XARGS} \
		${REINPLACE_CMD} -E -e '${REINPLACE}'

post-patch:
.for f in ${HTML1}
	@${ECHO} '$$html_directory/$f:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
.endfor
	@${ECHO} '$$manpage_directory/man1/posttls-finger.1:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
	@${ECHO} '$$command_directory/posttls-finger:f:root:-:755' \
		>> ${WRKSRC}/conf/postfix-files

post-patch-SPF-on:
	@${ECHO} '$$readme_directory/SPF_README:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
	@${REINPLACE_CMD} -E -e '${REINPLACE}' \
		${WRKSRC}/README_FILES/SPF_README

post-patch-VDA-on:
	@${ECHO} '$$readme_directory/VDA_README:f:root:-:644' \
		>> ${WRKSRC}/conf/postfix-files
	@${REINPLACE_CMD} -E -e '${REINPLACE}' \
		${WRKSRC}/README_FILES/VDA_README

do-configure:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.init makefiles \
	${MAKEFILEFLAGS} CCARGS="${POSTFIX_CCARGS}" \
	AUXLIBS="${POSTFIX_AUXLIBS}" && \
	${ECHO} "all: default" >> Makefile)

pre-install-INST_BASE-on:
	${MKDIR} ${STAGEDIR}/etc/rc.d

do-install:
	@(cd ${WRKSRC} && ${MAKE} non-interactive-package \
		install_root=${STAGEDIR} tempdir=${WRKDIR} \
		config_directory=${ETCDIR} \
		command_directory=${PREFIX}/sbin \
		daemon_directory=${DAEMONDIR} \
		html_directory=${READMEDIR} \
		mailq_path=${PREFIX}/bin/mailq \
		manpage_directory=${MANPREFIX}/man \
		newaliases_path=${PREFIX}/bin/newaliases \
		readme_directory=${READMEDIR} \
		sendmail_path=${PREFIX}/sbin/sendmail )

	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/rmail/rmail ${STAGEDIR}${PREFIX}/bin/rmail
	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl ${STAGEDIR}${PREFIX}/bin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-TEST-on:
	${INSTALL_PROGRAM} ${BINTEST:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MANTEST:S|^|${WRKSRC}/man/man1/|} ${STAGEDIR}${MANPREFIX}/man/man1

post-stage:
# == do not overwrite existing config
	${MV} ${STAGEDIR}${ETCDIR}/main.cf ${STAGEDIR}${ETCDIR}/main.cf.sample
	${MV} ${STAGEDIR}${ETCDIR}/master.cf ${STAGEDIR}${ETCDIR}/master.cf.sample

# Fix compressed man pages and strip executables
	${SED} -i '' -E -e "s|(man[158]/.*.[158]):|\1.gz:|g" ${STAGEDIR}${DAEMONDIR}/postfix-files
	-@${STRIP_CMD} ${STRIP_LIBEXEC:S|^|${STAGEDIR}${DAEMONDIR}/|}
	-@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*

.include <bsd.port.mk>
