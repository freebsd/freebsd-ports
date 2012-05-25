# New ports collection makefile for:	boinc
# Date created:				01 October 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	7.0.25
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Berkeley Open Infrastructure for Network Computing client

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(cpp|h)

BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	nobody
BOINC_CLIENT_HOME?=	/var/db/boinc

PLIST_SUB=	BOINC_CLIENT_HOME="${BOINC_CLIENT_HOME}" \
		BOINC_CLIENT_USER="${BOINC_CLIENT_USER}"

SUB_FILES=	pkg-install
SUB_LIST=	BOINC_CLIENT_HOME="${BOINC_CLIENT_HOME}" \
		BOINC_CLIENT_USER="${BOINC_CLIENT_USER}" \
		BOINC_CLIENT_GROUP="${BOINC_CLIENT_GROUP}" \
		PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"

USE_RC_SUBR=	boinc-client

CONFIGURE_ARGS=	--disable-server
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	CLIENT "Build BOINC client" on \
		MANAGER "Build BOINC manager GUI" on \
		X11 "Build graphics API" on \
		ALT "Accept Linux science applications" off \
		USER "Create/check BOINC client user" on \
		SKINS "Install more skins for BOINC manager" off \
		OPTIMIZE "Enable compiler optimization flags" off

.include <bsd.port.pre.mk>

.if defined(BOINC_USER) || defined(BOINC_GROUP) || defined(BOINC_HOME)
pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "===> The following variables were renamed:"
	@${ECHO_MSG} "===>     BOINC_USER BOINC_GROUP BOINC_HOME"
	@${ECHO_MSG} "===> Use new names of similar variables."
	@${ECHO_MSG}
	@exit 1
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

.if !defined(WITHOUT_MANAGER)
. if defined(WITHOUT_CLIENT)
.  undef WITHOUT_CLIENT
. endif
. if defined(WITHOUT_X11)
.  undef WITHOUT_X11
. endif
.endif

.if !defined(WITHOUT_X11)
USE_GL=		glut
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_MANAGER)
USE_XORG=	x11
USE_WX=		2.8+
USE_ICONV=	yes
WX_CONF_ARGS=	absolute
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify \
		sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--with-sqlite3-prefix=${LOCALBASE}
. if ${OSVERSION} < 900506 || (${OSVERSION} >= 1000000 && ${OSVERSION} < 1000002)
CPPFLAGS+=	-DNO_PER_THREAD_LOCALE
. endif
PLIST_SUB+=	BOINC_MANAGER=""
.else
CONFIGURE_ARGS+=--disable-manager --with-wx-config=false --without-x
PLIST_SUB+=	BOINC_MANAGER="@comment "
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
PLIST_SUB+=	BOINC_CLIENT=""
.else
CONFIGURE_ARGS+=--disable-client
PLIST_SUB+=	BOINC_CLIENT="@comment "
.endif

.if defined(WITHOUT_NLS) || defined(WITHOUT_MANAGER)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_ALT)
CONFIGURE_ARGS+=--with-boinc-alt-platform=i686-pc-linux-gnu
USE_LINUX=	yes
.endif

.if defined(WITH_SKINS)
PLIST_SUB+=	SKINS=""
.else
PLIST_SUB+=	SKINS="@comment "
.endif

.if !defined(WITHOUT_USER)
PLIST_SUB+=	USER=""
.else
PLIST_SUB+=	USER="@comment "
.endif

.if defined(WITH_OPTIMIZE)
CONFIGURE_ARGS+=--enable-optimize
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|client/scripts||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcrypto -ldl|-lcrypto|' ${WRKSRC}/configure
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's| locale||' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|$$$$mydir/$$$$ldir|&/LC_MESSAGES|' ${WRKSRC}/locale/Makefile.in
.endif
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's|@BUILD_GRAPHICS_API_TRUE@|#&|' ${WRKSRC}/api/Makefile.in
.endif

post-install:
.if !defined(WITHOUT_MANAGER)
	${MKDIR} ${LOCALBASE}/share/pixmaps
. for name in 16 32 48
	cd ${LOCALBASE}/share/pixmaps ; ${LN} -sf ${PREFIX}/share/boinc/boincmgr.${name}x${name}.png
. endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/config.h ${PREFIX}/include/boinc
	${INSTALL_DATA} ${WRKSRC}/lib/std_fixes.h ${PREFIX}/include/boinc
.if !defined(WITHOUT_X11)
. for name in api/boinc_gl.h api/graphics_api.h api/graphics_data.h \
	api/reduce.h api/txf_util.h
	${INSTALL_DATA} ${WRKSRC}/${name} ${PREFIX}/include/boinc
. endfor
. if defined(WITHOUT_MANAGER)
	${MKDIR} ${PREFIX}/share/boinc
. endif
	${CP} -R ${WRKSRC}/api/txf ${PREFIX}/share/boinc
.endif
.if defined(WITH_SKINS)
	${CP} -R ${WRKSRC}/clientgui/skins ${PREFIX}/share/boinc
.elif defined(WITH_MANAGER)
	${MKDIR} ${PREFIX}/share/boinc/skins
	${CP} -R ${WRKSRC}/clientgui/skins/Default ${PREFIX}/share/boinc/skins
.endif
.if !defined(WITHOUT_USER)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
