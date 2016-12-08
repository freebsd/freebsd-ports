# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	boinc-client
PORTVERSION=	7.2.33
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	LOCAL/rene

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Berkeley Open Infrastructure for Network Computing client

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf dos2unix gmake libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.xpm

USERS=		boinc
GROUPS=		boinc

BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	BOINC_CLIENT_HOME="${BOINC_CLIENT_HOME}" \
		BOINC_CLIENT_USER="${BOINC_CLIENT_USER}" \
		BOINC_CLIENT_GROUP="${BOINC_CLIENT_GROUP}" \
		PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=	--disable-server
CONFIGURE_ENV=	OBJCXX="${CXX}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		CLIENT MANAGER NLS X11 LINUX USER SKINS
OPTIONS_DEFAULT=	CLIENT MANAGER X11 USER
OPTIONS_GROUP=		SCRIPT
OPTIONS_GROUP_SCRIPT=	NO_GUI_RPC NO_NET_INFO
CLIENT_DESC=		Build BOINC client
MANAGER_DESC=		Build BOINC manager GUI
X11_DESC=		Build graphics API
LINUX_DESC=		Accept Linux science applications
USER_DESC=		Create/check BOINC client user and directory
SKINS_DESC=		Install more skins for BOINC manager
SCRIPT_DESC=		Command line options in script
NO_GUI_RPC_DESC=	Disable GUI RPC and socket (breaks boinc_curses)
NO_NET_INFO_DESC=	Do not send host address and name to servers

OPTIONS_SUB=		yes

MANAGER_USES=		iconv
MANAGER_LIB_DEPENDS=	libnotify.so:devel/libnotify \
			libsqlite3.so:databases/sqlite3
MANAGER_CONFIGURE_ON=	--with-sqlite3-prefix=${LOCALBASE}
MANAGER_CONFIGURE_OFF=	--with-wx-config=false --without-x
MANAGER_CONFIGURE_ENABLE=manager
MANAGER_USE=		XORG=x11,xext,xscrnsaver WX=2.8

CLIENT_CONFIGURE_ENABLE=client
CLIENT_LIB_DEPENDS=	libcurl.so:ftp/curl
CLIENT_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CLIENT_USE=		RC_SUBR=boinc-client

LINUX_CONFIGURE_ON=	--with-boinc-alt-platform=i686-pc-linux-gnu
LINUX_USES=		linux

X11_USES=		jpeg
X11_USE=		GL=glut XORG=xmu,xi
X11_CONFIGURE_OFF=	ax_cv_check_glut_libglut=no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANAGER}
WX_CONF_ARGS=	absolute
SUB_LIST+=	OPTION_MANAGER="true"
.else
SUB_LIST+=	OPTION_MANAGER=""
.endif

.if ${PORT_OPTIONS:MCLIENT}
SUB_LIST+=	OPTION_NO_GUI_RPC=${PORT_OPTIONS:MNO_GUI_RPC:S/^NO_GUI_RPC$/--no_gui_rpc/} \
		OPTION_NO_NET_INFO=${PORT_OPTIONS:MNO_NET_INFO:S/^NO_NET_INFO$/--suppress_net_info/}
.endif

.if ${PORT_OPTIONS:MUSER}
SUB_LIST+=	OPTION_USER="true"
.else
SUB_LIST+=	OPTION_USER=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/client/hostinfo_unix.cpp
	@${REINPLACE_CMD} -e 's|client/scripts||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|$$$$mydir/$$$$ldir|&/LC_MESSAGES|' \
		${WRKSRC}/locale/Makefile.am
# avoid build conflict with archivers/libzip
	@${MV} ${WRKSRC}/zip/unzip/zip.h ${WRKSRC}/zip/unzip/boinczip.h
	@${MV} ${WRKSRC}/zip/zip/zip.h ${WRKSRC}/zip/zip/boinczip.h
	@${REINPLACE_CMD} -e 's|zip/zip.h|zip/boinczip.h|' \
	    ${WRKSRC}/zip/boinc_zip.cpp
	@${REINPLACE_CMD} -e 's|"zip.h"|"boinczip.h"|' \
	    ${WRKSRC}/zip/unzip/crc32.c ${WRKSRC}/zip/unzip/ttyio.c \
	    ${WRKSRC}/zip/zip/deflate.c ${WRKSRC}/zip/zip/trees.c \
	    ${WRKSRC}/zip/zip/unix/z_unix.c ${WRKSRC}/zip/zip/util.c \
	    ${WRKSRC}/zip/zip/z_fileio.c ${WRKSRC}/zip/zip/z_globals.c \
	    ${WRKSRC}/zip/zip/zip.c ${WRKSRC}/zip/zip/zipfile.c \
	    ${WRKSRC}/zip/zip/zipup.c

post-install:
.for name in config.h project_specific_defines.h api/reduce.h \
	lib/opencl_boinc.h lib/shmem.h lib/std_fixes.h
	${INSTALL_DATA} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/include/boinc
.endfor

post-install-MANAGER-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc
.for name in 16 32 48
	${INSTALL_DATA} ${WRKSRC}/clientgui/res/boincmgr.${name}x${name}.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps
.endfor
.if ${PORT_OPTIONS:MSKINS}
	(cd ${WRKSRC}/clientgui && \
	${COPYTREE_SHARE} skins ${STAGEDIR}${PREFIX}/share/boinc/ )
.else
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc/skins
	(cd ${WRKSRC}/clientgui/skins && \
	${COPYTREE_SHARE} Default ${STAGEDIR}${PREFIX}/share/boinc/skins/ )
.endif

post-install-X11-on:
.for name in api/boinc_gl.h api/graphics_api.h api/graphics_data.h \
	api/ttfont.h
	${INSTALL_DATA} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/include/boinc
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boinc/ttf
	(cd ${WRKSRC}/api/ttf/liberation-fonts-ttf-2.00.0 && \
	    ${COPYTREE_SHARE} \*.ttf ${STAGEDIR}${PREFIX}/share/boinc/ttf/ )

.include <bsd.port.mk>
