# Created by: Nikola Kolev <koue@chaosophia.net>
# $FreeBSD$

PORTNAME=	samhain
PORTVERSION=	4.2.4
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/archive/
DISTNAME=	samhain_signed-${PORTVERSION}

MAINTAINER=	koue@chaosophia.net
COMMENT=	Samhain Intrusion Detection System

LICENSE=	GPLv2

BROKEN_aarch64=		fails to build: undefined reference to sbrk
BROKEN_mips=		fails to configure: error: Could not find the libwrap library
BROKEN_mips64=		fails to configure: error: Could not find the libwrap library

OPTIONS_DEFINE=	ASM DB_RELOAD DEBUG DNMALLOC DOCS ENCRYPT GNUPG IPV6 KCHECK \
		LIBWRAP LOGFILE_MONITOR LOGIN_WATCH MAIL MOUNTS_CHECK MYSQL \
		ODBC PGSQL PORT_CHECK PROCESS_CHECK POSIX_ACL PRELUDE PTRACE \
		SRP STATIC SUIDCHECK UDP USERFILES XML_LOGS
OPTIONS_DEFAULT=ASM DNMALLOC ENCRYPT LIBWRAP MAIL SRP

DB_RELOAD_DESC=	Enable database reload on SIGHUP
DNMALLOC_DESC=	Enable dnmalloc
ENCRYPT_DESC=	Enable client/server encryption
KCHECK_DESC=	Enable rogue KLD detection
LOGFILE_MONITOR_DESC=	Enable monitor logfiles
LOGIN_WATCH_DESC=	Enable watch for login/logout
MAIL_DESC=	Enable internal SMTP mailer
MOUNTS_CHECK_DESC=	Enable check mount options on filesystems
PORT_CHECK_DESC=	Enable check ports
PROCESS_CHECK_DESC=	Enable check processes
POSIX_ACL_DESC=	Enable check posix acls
PRELUDE_DESC=	Enable Prelude Framework support
PTRACE_DESC=	Enable use anti-debugger options
SRP_DESC=	Enable SRP for authentication
SUIDCHECK_DESC=	Enable check for suid/sgid files
UDP_DESC=	Enable UDP server
USERFILES_DESC=	Enable check for users config files
XML_LOGS_DESC=	Enable XML-formatted logs

OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logserver=true \
		--with-altlogserver=true \
		--with-timeserver=true \
		--with-alttimeserver=true

USES=			shebangfix
SHEBANG_FILES=		scripts/samhainadmin.pl.in

ASM_CONFIGURE_ENABLE=		asm

DB_RELOAD_CONFIGURE_ENABLE=	db-reload

DEBUG_CONFIGURE_ENABLE=		debug

DNMALLOC_CONFIGURE_ENABLE=	dnmalloc

ENCRYPT_CONFIGURE_ENABLE=	encrypt

GNUPG_CONFIGURE_WITH=		gpg=${PREFIX}/bin/gpg
GNUPG_BUILD_DEPENDS=		gpg:security/gnupg

IPV6_CONFIGURE_ENABLE=		ipv6

KCHECK_CONFIGURE_WITH=		kcheck

LIBWRAP_CONFIGURE_WITH=		libwrap

LOGFILE_MONITOR_CONFIGURE_ENABLE=	logfile-monitor

LOGIN_WATCH_CONFIGURE_ENABLE=	login-watch

MAIL_CONFIGURE_ENABLE=		mail

MOUNTS_CHECK_CONFIGURE_ENABLE=	mounts-check

MYSQL_USES=			mysql
MYSQL_CONFIGURE_ARGS=		--with-database=mysql

ODBC_CONFIGURE_ARGS=		--with-database=odbc
ODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC

PGSQL_USES=			pgsql
PGSQL_CONFIGURE_ARGS=		--with-database=postgresql

PORT_CHECK_CONFIGURE_ENABLE=	port-check

PROCESS_CHECK_CONFIGURE_ENABLE=	process-check

POSIX_ACL_CONFIGURE_ENABLE=	posix-acl

PRELUDE_LIB_DEPENDS=		prelude:security/libprelude
PRELUDE_CONFIGURE_WITH=		prelude

PTRACE_CONFIGURE_ENABLE=	ptrace

SRP_CONFIGURE_ENABLE=		srp

STATIC_CONFIGURE_ENABLE=	static

SUIDCHECK_CONFIGURE_ENABLE=	suidcheck

UDP_CONFIGURE_ENABLE=		udp

USERFILES_CONFIGURE_ENABLE=	userfiles

XML_LOGS_CONFIGURE_ENABLE=	xml-log

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_RUNAS_USER)
CONFIGURE_ARGS+=	--enable-identity=${WITH_RUNAS_USER}
.else
CONFIGURE_ARGS+=	--enable-identity=yule
.endif

.if defined(WITH_CLIENT)
CONFIGURE_ARGS+=	--enable-network=client \
			--with-data-file=REQ_FROM_SERVER/var/lib/samhain/data.samhain \
			--with-config-file=REQ_FROM_SERVER
PLIST_SUB+=		SAMHAIN="" SETPWD="" YULE="@comment "
EXTRA_PATCHES+=		${FILESDIR}/fixsamhainrc.patch
MAN5+=			samhainrc.5
MAN8+=			samhain.8
.elif defined(WITH_SERVER)
USERS=			yule
GROUPS=			yule
CONFIGURE_ARGS+=	--enable-network=server
SUB_LIST+=		WITH_YULE="yes"
PLIST_SUB+=		YULE="" SAMHAIN="@comment " SETPWD="@comment "
EXTRA_PATCHES+=		${FILESDIR}/fixyulerc.patch
MAN5+=			yulerc.5
MAN8+=			yule.8
.else
SUB_LIST+=		WITH_YULE=""
PLIST_SUB+=		SAMHAIN="" YULE="@comment " SETPWD="@comment "
EXTRA_PATCHES+=		${FILESDIR}/fixsamhainrc.patch
MAN5+=			samhainrc.5
MAN8+=			samhain.8
.endif

pre-everything::

.if !defined(WITH_CLIENT) && !defined(WITH_SERVER)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building Samhain in standalone mode."
	@${ECHO_MSG} "If you wish to enable networked mode, please hit CTRL-C"
	@${ECHO_MSG} "now, and build samhain from the samhain-client and"
	@${ECHO_MSG} "samhain-server ports."
	@${ECHO_MSG}
.endif

.if defined(WITH_CLIENT) && defined(WITH_SERVER)
IGNORE=		can't build client and server at once
.endif

.if ${PORT_OPTIONS:MKCHECK}
	@${ECHO_MSG}
	@${ECHO_MSG} "Building with kernel checking requires reading /dev/kmem"
	@${ECHO_MSG} "and /dev/mem. If you're not building as root, please hit"
	@${ECHO_MSG} "Control-C and restart the build as root."
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MXML_LOGS}
IGNORE=		xml logging is required to log to MySQL
.endif

.if ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MXML_LOGS}
IGNORE=		xml logging is required to log to Postgres
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKSRC}.tar.gz
	@${RM} ${WRKSRC}.tar.gz ${WRKSRC}.tar.gz.asc

post-install:
.if !defined(WITH_SERVER)
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${STAGEDIR}${PREFIX}/etc/rc.d/samhain.sh
	@${CP} ${WRKSRC}/samhainrc ${STAGEDIR}${PREFIX}/etc/samhainrc.sample
	@${CHGRP} wheel ${STAGEDIR}${PREFIX}/etc/samhainrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/samhain
.else
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${STAGEDIR}${PREFIX}/etc/rc.d/yule.sh
	@${CP} ${WRKSRC}/yulerc ${STAGEDIR}${PREFIX}/etc/yulerc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/yule
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/yulectl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/yule_setpwd
.endif
.if defined(WITH_CLIENT)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/samhain_setpwd
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-2_4.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server-troubleshooting.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-samhain+GnuPG.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-write-modules.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/FAQ.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/README.UPGRADE ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/BUGS ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/sh_mounts.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/sh_userfiles.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
