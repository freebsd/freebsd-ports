# New ports collection makefile for:	samhain
# Date created:				9 January 2003
# Whom:					lx
#
# $FreeBSD$
#
#
# This port recognizes the following non-boolean tunables:
#
# WITH_RUNAS_USER:
#	Whe building with "WITH_SERVER" defined, the username of the
#	account Yule will run as. Defaults to "yule".
#
# WITH_LOG_SERVER, WITH_ALT_LOG_SERVER. When "WITH_CLIENT" is defined,
# 	these specify what server the client will fetch configuration
#	and database files from. This can also be defined at runtime.
#

PORTNAME=	samhain
PORTVERSION=	2.0.8
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/archive/ \
		http://cold.darkambient.net/
DISTFILES=	samhain_signed-${PORTVERSION}.tar.gz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The Samhain Intrusion Detection System

OPTIONS=	KCHECK "Enable rogue KLD detection" off \
		GPG "Enable GnuPG support" off \
		MYSQL "Enable MySQL logging" off \
		POSTGRESQL "Enable PostgreSQL logging" off \
		LIBWRAP "Enable TCP wrapper support" on \
		CLIENT "Build as Samhain network client" off \
		SERVER "Build as Yule network server" off

.include <bsd.port.pre.mk>

.if defined(WITH_GPG)
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-login-watch --localstatedir=/var \
		--mandir=${PREFIX}/man --enable-suidcheck

.if defined(WITH_RUNAS_USER)
CONFIGURE_ARGS+=	--enable-identity=${WITH_RUNAS_USER}
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
			--with-libs=-L${LOCALBASE}/lib/mysql --enable-xml-log
.endif
.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-database=postgresql --enable-xml-log
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
PLIST_SUB+=	YULE="" SAMHAIN="@comment " SETPWD="@comment "
EXTRA_PATCHES+=	${FILESDIR}/fixyulerc.patch
MAN5=	yulerc.5
MAN8=	yule.8
.else
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

pre-everything::

.if !defined(WITH_CLIENT) && !defined(WITH_SERVER)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building in standalone mode."
	@${ECHO_MSG} "If you wish to enable networked mode, please hit CTRL-C"
	@${ECHO_MSG} "now, review the options in the Makefile, and make"
	@${ECHO_MSG} "with WITH_SERVER=yes or WITH_CLIENT=yes."
	@${ECHO_MSG}
.endif

.if defined(WITH_CLIENT) && defined(WITH_SERVER)
	@${ECHO_MSG}
	@${ECHO_MSG} "Can't build client and server at once!"
	@${ECHO_MSG}
.error "Can't build client and server at once!"
.endif

.if defined(WITH_KCHECK)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building with kernel checking requires reading /dev/kmem"
	@${ECHO_MSG} "and /dev/mem. If you're not building as root, please hit"
	@${ECHO_MSG} "Control-C and restart the build as root."
	@${ECHO_MSG}
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKSRC}.tar.gz
	@${RM} ${WRKSRC}.tar.gz ${WRKSRC}.tar.gz.asc

post-install:
.if !defined(WITH_SERVER)
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/samhain.sh.sample
	@${CP} ${WRKSRC}/samhainrc ${PREFIX}/etc/samhainrc.sample
.else
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/yule.sh.sample
	@${CP} ${WRKSRC}/yulerc ${PREFIX}/etc/yulerc.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-2_0.ps ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-2_0.html.tar ${DOCSDIR}
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

install-user:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-user)

.include <bsd.port.post.mk>
