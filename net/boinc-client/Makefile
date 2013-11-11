# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	boinc-client
PORTVERSION=	7.2.28
CATEGORIES=	net
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Berkeley Open Infrastructure for Network Computing client

USES=		gmake pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.xpm

USERS=		boinc
GROUPS=		boinc

BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc

SUB_FILES=	pkg-install
SUB_LIST=	BOINC_CLIENT_HOME="${BOINC_CLIENT_HOME}" \
		BOINC_CLIENT_USER="${BOINC_CLIENT_USER}" \
		BOINC_CLIENT_GROUP="${BOINC_CLIENT_GROUP}" \
		PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=	--disable-server
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		CLIENT MANAGER X11 LINUX USER SKINS
OPTIONS_DEFAULT=	CLIENT MANAGER X11 USER
OPTIONS_GROUP=		SCRIPT
OPTIONS_GROUP_SCRIPT=	NO_GUI_RPC NO_NET_INFO
CLIENT_DESC=		Build BOINC client
MANAGER_DESC=		Build BOINC manager GUI
X11_DESC=		Build graphics API
LINUX_DESC=		Accept Linux science applications
USER_DESC=		Create/check BOINC client user and directory
SKINS_DESC=		Install more skins for BOINC manager
#OPTIMIZE_DESC=		Enable compiler optimization flags
SCRIPT_DESC=		Command line options in script
NO_GUI_RPC_DESC=	Disable GUI RPC and socket (breaks boinc_curses)
NO_NET_INFO_DESC=	Do not send host address and name to servers

OPTIONS_SUB=		yes

MANAGER_USES=		iconv
MANAGER_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
			libsqlite3.so:${PORTSDIR}/databases/sqlite3
MANAGER_CONFIGURE_ON=	--with-sqlite3-prefix=${LOCALBASE}
MANAGER_CONFIGURE_OFF=	--with-wx-config=false --without-x
MANAGER_CONFIGURE_ENABLE=manager
MANAGER_USE=		XORG=x11 WX=2.8+

CLIENT_CONFIGURE_WITH=	client
CLIENT_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CLIENT_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CLIENT_USE=		RC_SUBR=boinc-client

LINUX_CONFIGURE_ON=	--with-boinc-alt-platform=i686-pc-linux-gnu
LINUX_USE=		LINUX=yes

#OPTIMIZE_CONFIGURE_ENBABLE=	optimize

X11_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
X11_USE=		GL=glut XORG=xmu XORG=xi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANAGER}
#PORT_OPTIONS+=	CLIENT X11
WX_CONF_ARGS=	absolute
. if ${OSVERSION} < 900506 || (${OSVERSION} >= 1000000 && ${OSVERSION} < 1000002)
CPPFLAGS+=	-DNO_PER_THREAD_LOCALE
. endif
SUB_LIST+=	OPTION_MANAGER="true"
.else
SUB_LIST+=	OPTION_MANAGER=""
.endif

.if ${PORT_OPTIONS:MCLIENT}
SUB_LIST+=	OPTION_NO_GUI_RPC=${PORT_OPTIONS:MNO_GUI_RPC:S/^NO_GUI_RPC$/--no_gui_rpc/} \
		OPTION_NO_NET_INFO=${PORT_OPTIONS:MNO_NET_INFO:S/^NO_NET_INFO$/--suppress_net_info/}
#.else
#PORT_OPTIONS:=	${PORT_OPTIONS:NUSER}
.endif

# XXX NLS is not filled in by OPTIONS_SUB ?
.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MUSER}
SUB_LIST+=	OPTION_USER="true"
.else
SUB_LIST+=	OPTION_USER=""
.endif

PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

# avoid build conflict with archivers/libzip
post-extract:
	${MV} ${WRKSRC}/zip/unzip/zip.h ${WRKSRC}/zip/unzip/boinczip.h
	${MV} ${WRKSRC}/zip/zip/zip.h ${WRKSRC}/zip/zip/boinczip.h
	${REINPLACE_CMD} -e 's|zip/zip.h|zip/boinczip.h|' \
	    ${WRKSRC}/zip/boinc_zip.cpp
	${REINPLACE_CMD} -e 's|"zip.h"|"boinczip.h"|' \
	    ${WRKSRC}/zip/unzip/crc32.c ${WRKSRC}/zip/unzip/ttyio.c \
	    ${WRKSRC}/zip/zip/deflate.c ${WRKSRC}/zip/zip/trees.c \
	    ${WRKSRC}/zip/zip/unix/z_unix.c ${WRKSRC}/zip/zip/util.c \
	    ${WRKSRC}/zip/zip/z_fileio.c ${WRKSRC}/zip/zip/z_globals.c \
	    ${WRKSRC}/zip/zip/zip.c ${WRKSRC}/zip/zip/zipfile.c \
	    ${WRKSRC}/zip/zip/zipup.c

pre-configure:
	(cd ${WRKSRC} ; ./_autosetup)

post-configure:
	@${REINPLACE_CMD} -e 's|client/scripts||' ${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|$$$$mydir/$$$$ldir|&/LC_MESSAGES|' \
	    ${WRKSRC}/locale/Makefile.in
.else
	@${REINPLACE_CMD} -e 's| locale||' ${WRKSRC}/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e 's|@BUILD_GRAPHICS_API_TRUE@|#&|' \
	    ${WRKSRC}/api/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MMANAGER} || ${PORT_OPTIONS:MX11}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc
.endif
.if ${PORT_OPTIONS:MMANAGER}
. for name in 16 32 48
	${INSTALL_DATA} ${WRKSRC}/clientgui/res/boincmgr.${name}x${name}.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps
. endfor
. if ${PORT_OPTIONS:MSKINS}
	(cd ${WRKSRC}/clientgui && \
	${COPYTREE_SHARE} skins ${STAGEDIR}${PREFIX}/share/boinc/ )
. else
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc/skins
	(cd ${WRKSRC}/clientgui/skins && \
	${COPYTREE_SHARE} Default ${STAGEDIR}${PREFIX}/share/boinc/skins/ )
. endif
.endif
. for name in config.h project_specific_defines.h api/reduce.h lib/shmem.h \
	lib/std_fixes.h
	${INSTALL_DATA} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/include/boinc
. endfor
.if ${PORT_OPTIONS:MX11}
. for name in api/boinc_gl.h api/graphics_api.h api/graphics_data.h \
	api/ttfont.h
	${INSTALL_DATA} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/include/boinc
. endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc/ttf
	(cd ${WRKSRC}/api/ttf/liberation-fonts-ttf-2.00.0 && \
	    ${COPYTREE_SHARE} \*.ttf ${STAGEDIR}${PREFIX}/share/boinc/ttf/ )
.endif

.include <bsd.port.mk>
