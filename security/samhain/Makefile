# New ports collection makefile for:	samhain
# Date created:				9 January 2003
# Whom:					lx
#
# $FreeBSD$

PORTNAME=	samhain
PORTVERSION=	2.7.1
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/archive/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	samhain_signed-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	The Samhain Intrusion Detection System

OPTIONS=	KCHECK "Enable rogue KLD detection" off \
		GPG "Enable GnuPG support" off \
		MYSQL "Enable MySQL logging" off \
		POSTGRESQL "Enable PostgreSQL logging" off \
		XML_LOGS "Enable XML-formatted logs" on \
		LIBWRAP "Enable TCP wrapper support" on \
		PRELUDE "Enable Prelude Framework support" off

SUB_FILES+=	pkg-install

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFLICTS=	samhain-client-2*

LICENSE=	GPLv2

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${ARCH} == "amd64" && ${OSVERSION} >= 800000
BROKEN=		does not compile
.elif ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if defined(WITH_GPG)
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-login-watch --localstatedir=/var \
		--enable-suidcheck

.if !defined(WITHOUT_XML_LOGS)
CONFIGURE_ARGS+=	--enable-xml-log
.endif
.if defined(WITH_RUNAS_USER)
CONFIGURE_ARGS+=	--enable-identity=${WITH_RUNAS_USER}
.else
CONFIGURE_ARGS+=	--enable-identity=yule
.endif
.if defined(WITH_KCHECK)
CONFIGURE_ARGS+=	--with-kcheck
.endif
.if defined(WITH_GPG)
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg
.endif
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-database=mysql \
			--with-cflags=-I${LOCALBASE}/include/mysql \
			--with-libs=-L${LOCALBASE}/lib/mysql
.endif
.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-database=postgresql
.endif
.if !defined(WITHOUT_LIBWRAP)
CONFIGURE_ARGS+=	--with-libwrap
.endif
.if defined(WITH_CLIENT)
CONFIGURE_ARGS+=	--enable-network=client \
		--with-data-file=REQ_FROM_SERVER/var/lib/samhain/data.samhain \
		--with-config-file=REQ_FROM_SERVER
PLIST_SUB+=	SAMHAIN="" SETPWD="" YULE="@comment "
EXTRA_PATCHES+=	${FILESDIR}/fixsamhainrc.patch
MAN5=	samhainrc.5
MAN8=	samhain.8
.elif defined(WITH_SERVER)
CONFIGURE_ARGS+=	--enable-network=server
SUB_LIST+=	WITH_YULE="yes"
PLIST_SUB+=	YULE="" SAMHAIN="@comment " SETPWD="@comment "
EXTRA_PATCHES+=	${FILESDIR}/fixyulerc.patch
MAN5=	yulerc.5
MAN8=	yule.8
.else
SUB_LIST+=	WITH_YULE=""
PLIST_SUB+=	SAMHAIN="" YULE="@comment " SETPWD="@comment "
EXTRA_PATCHES+=	${FILESDIR}/fixsamhainrc.patch
MAN5=	samhainrc.5
MAN8=	samhain.8
.endif
.if defined(WITH_LOG_SERVER)
CONFIGURE_ARGS+=	--with-logserver=${WITH_LOG_SERVER}
.endif
.if defined(WITH_ALT_LOG_SERVER)
CONFIGURE_ARGS+=	--with-altlogserver=${WITH_ALT_LOG_SERVER}
.endif
.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.20:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--with-prelude
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

.if defined(WITH_KCHECK)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building with kernel checking requires reading /dev/kmem"
	@${ECHO_MSG} "and /dev/mem. If you're not building as root, please hit"
	@${ECHO_MSG} "Control-C and restart the build as root."
	@${ECHO_MSG}
.endif

.if defined(WITH_MYSQL) && !defined(WITH_XML_LOGS)
IGNORE=		XML logging is required to log to MySQL
.endif

.if defined(WITH_POSTGRESQL) && !defined(WITH_XML_LOGS)
IGNORE=		XML logging is required to log to Postgres
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKSRC}.tar.gz
	@${RM} ${WRKSRC}.tar.gz ${WRKSRC}.tar.gz.asc

pre-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(WITH_SERVER)
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/samhain.sh
	@${CP} ${WRKSRC}/samhainrc ${PREFIX}/etc/samhainrc.sample
	@${CHGRP} wheel ${PREFIX}/etc/samhainrc.sample
.else
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/yule.sh
	@${CP} ${WRKSRC}/yulerc ${PREFIX}/etc/yulerc.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-2_3.pdf ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server-troubleshooting.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-samhain+GnuPG.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-write-modules.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/FAQ.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/README.UPGRADE ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/BUGS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/sh_mounts.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/sh_userfiles.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
