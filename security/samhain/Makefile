# New ports collection makefile for:	samhain
# Date created:				9 January 2003
# Whom:					lx
#
# $FreeBSD$
#
#
# This port recognizes the following tunables:
#
# RUNAS_USER:
#	The username of the account Yule will run as. Usually just "yule".
#
# WITH_GPG:
#	Instructs the port to sign configuration files using the
# 	GNU Privacy Guard.
#
# WITH_KCHECK:
#	Enable support for rogue kernel module detection.
#
# WITH_MYSQL:
#	Enable support for logging to a MySQL database.  Due to there
#	being multiple current versions of MySQL, dependency for this
#	is NOT checked.
#
# WITH_POSTGRESQL:
#	Enable support for logging to a Postgres database.  Untested.
#
# WITH_LIBWRAP:
#	Enable support for TCP wrappers.
#
# SERVER:
#	Builds as Yule, Samhain's central logging server.  Mutually exclusive
#	with CLIENT.
#
# CLIENT:
# 	Builds as a client to Yule.  Fetches configuration files
#	and signature database from LOG_SERVER, and optionally, ALT_LOG_SERVER.
#

PORTNAME=	samhain
PORTVERSION=	1.8.5
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/archive/ \
		http://cold.darkambient.net/
DISTFILES=	samhain_signed-${PORTVERSION}.tar.gz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The Samhain Intrusion Detection System

.if defined(WITH_GPG)
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-login-watch --localstatedir=/var \
		--mandir=${PREFIX}/man --enable-suidcheck

.if defined(RUNAS_USER)
CONFIGURE_ARGS+=	--enable-identity=${RUNAS_USER}
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
.if defined(WITH_LIBWRAP)
CONFIGURE_ARGS+=	--with-libwrap
.endif
.if defined(CLIENT)
CONFIGURE_ARGS+=	--enable-network=client \
		--with-data-file=REQ_FROM_SERVER/var/lib/samhain/data.samhain \
		--with-config-file=REQ_FROM_SERVER
PLIST_SUB+=	SAMHAIN="" SETPWD="" YULE="@comment "
EXTRA_PATCHES+=	${FILESDIR}/fixsamhainrc.patch
MAN5=	samhainrc.5
MAN8=	samhain.8
.elif defined(SERVER)
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
.if defined(LOG_SERVER)
CONFIGURE_ARGS+=	--with-logserver=${ALT_LOG_SERVER}
.endif
.if defined(ALT_LOG_SERVER)
CONFIGURE_ARGS+=	--with-altlogserver=${ALT_LOG_SERVER}
.endif

pre-everything::

.if !defined(CLIENT) && !defined(SERVER)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building in standalone mode."
	@${ECHO_MSG} "If you wish to enable networked mode, please hit CTRL-C"
	@${ECHO_MSG} "now and make with SERVER=yes or CLIENT=yes."
	@${ECHO_MSG}
.endif

.if defined(CLIENT) && defined(SERVER)
	@${ECHO_MSG}
	@${ECHO_MSG} "Can't build client and server at once!"
	@${ECHO_MSG}
.error "Can't build client and server at once!"
.endif

.if defined(WITH_KCHECK)
	@${ECHO_MSG}
	@${ECHO_MSG} "Building with kernel checking requires reading /dev/kmem."
	@${ECHO_MSG} "If you're not building as root, please hit Control-C and"
	@${ECHO_MSG} "restart the build as root."
	@${ECHO_MSG}
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKSRC}.tar.gz
	@${RM} ${WRKSRC}.tar.gz ${WRKSRC}.tar.gz.asc

post-install:
.if !defined(SERVER)
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/samhain.sh.sample
.else
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/yule.sh.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-1_8.ps ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-1_8.html.tar ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-samhain+GnuPG.html ${DOCSDIR}
.endif

install-user:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-user)

.include <bsd.port.mk>
