PORTNAME=	boinc-client
DISTVERSIONPREFIX=	client_release/8.2/
DISTVERSION=	8.2.13
CATEGORIES=	net

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Berkeley Open Infrastructure for Network Computing client
WWW=		https://boinc.berkeley.edu/ \
		https://github.com/BOINC/boinc/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	BOINC
GH_PROJECT=	boinc
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-server
CONFIGURE_ENV=	OBJCXX="${CXX}"

INSTALL_TARGET=	install-strip

LDFLAGS+=	-lexecinfo

DATADIR=	${PREFIX}/share/boinc
PORTSCOUT=	limit:^8\.2\.\d+
SUB_FILES=	pkg-deinstall pkg-install
SUB_LIST=	BOINC_CLIENT_GROUP="${BOINC_CLIENT_GROUP}" \
		BOINC_CLIENT_HOME="${BOINC_CLIENT_HOME}" \
		BOINC_CLIENT_USER="${BOINC_CLIENT_USER}" \
		LOCALBASE="${LOCALBASE}" \
		PREFIX="${PREFIX}"

USERS=		boinc
GROUPS=		boinc

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		CLIENT MANAGER NLS SKINS USER X11
OPTIONS_DEFINE_aarch64=	LINUX LINUXGL LINUXGLU
OPTIONS_DEFINE_amd64=	LINUX LINUXGL LINUXGLU
OPTIONS_DEFINE_i386=	LINUX LINUXGL LINUXGLU
OPTIONS_DEFAULT=	CLIENT MANAGER NLS SKINS USER X11
OPTIONS_DEFAULT_aarch64=CLIENT LINUX LINUXGL LINUXGLU MANAGER NLS SKINS USER X11
OPTIONS_DEFAULT_amd64=	CLIENT LINUX LINUXGL LINUXGLU MANAGER NLS SKINS USER X11
OPTIONS_DEFAULT_i386=	CLIENT LINUX LINUXGL LINUXGLU MANAGER NLS SKINS USER X11
OPTIONS_GROUP=		SCRIPT
OPTIONS_GROUP_SCRIPT=	NO_GUI_RPC NO_NET_INFO
OPTIONS_SUB=		yes

CLIENT_DESC=		Build BOINC client
LINUXGLU_DESC=		Support OpenGL Utility Library (libGLU) for GNU/Linux science applications
LINUXGL_DESC=		Support OpenGL (libGL) for GNU/Linux science applications
LINUX_DESC=		Accept science applications for GNU/Linux
MANAGER_DESC=		Build BOINC GUI manager
NLS_DESC=		Install language translations for use in the GUI
NO_GUI_RPC_DESC=	Disable GUI RPC socket (breaks boinc_curses)
NO_NET_INFO_DESC=	Do not send host name and address to servers
SCRIPT_DESC=		Command-line options in script
SKINS_DESC=		Install more skins for BOINC manager
USER_DESC=		Create/check user directory
X11_DESC=		Build graphics API

CLIENT_LIB_DEPENDS=		libcurl.so:ftp/curl \
				libfreetype.so:print/freetype2
CLIENT_RUN_DEPENDS=		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CLIENT_USE=			RC_SUBR=boinc-client
CLIENT_CONFIGURE_ENABLE=	client

LINUXGLU_IMPLIES=		LINUXGL
LINUXGLU_USE=			LINUX=dri
LINUXGL_IMPLIES=		LINUX
LINUXGL_USE=			LINUX=libglvnd
LINUX_USES=			linux
LINUX_CONFIGURE_ON=		${LINUX_CONFIGURE_ON_${ARCH}}
# https://boinc.berkeley.edu/trac/wiki/BoincPlatforms
LINUX_CONFIGURE_ON_aarch64=	--with-boinc-alt-platform=aarch64-unknown-linux-gnu
LINUX_CONFIGURE_ON_amd64=	--with-boinc-alt-platform=x86_64-pc-linux-gnu
LINUX_CONFIGURE_ON_i386=	--with-boinc-alt-platform=i686-pc-linux-gnu

MANAGER_LIB_DEPENDS=		libfreetype.so:print/freetype2 \
				libnotify.so:devel/libnotify \
				libxcb-util.so:x11/xcb-util \
				libxkbcommon.so:x11/libxkbcommon
MANAGER_USES=			desktop-file-utils gnome iconv xorg
MANAGER_USE=			GNOME=atk,cairo,gdkpixbuf,glib20,gtk30,pango \
				WX=3.2+ \
				XORG=x11,xcb,xext,xscrnsaver
MANAGER_CONFIGURE_ENABLE=	manager
MANAGER_CONFIGURE_WITH=		wx-config

NLS_USES=	gettext-tools

X11_USES=		desktop-file-utils gl jpeg xorg
X11_USE=		GL=glut \
			XORG=x11,xi,xmu,xscrnsaver
X11_CONFIGURE_OFF=	ax_cv_check_glut_libglut=no
X11_CONFIGURE_WITH=	x

BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc
BOINC_CLIENT_USER?=	boinc

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
	@${REINPLACE_CMD} -e 's|client/scripts||' ${WRKSRC}/Makefile.am

post-patch-X11-off:
	@${REINPLACE_CMD} -e 's|enable_xss="yes"|enable_xss="no"|' ${WRKSRC}/configure.ac

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.h api/*.h lib/*.h ${STAGEDIR}${PREFIX}/include/boinc

post-install-MANAGER-on:
	cd ${WRKSRC}/packages/generic/sea && \
		${INSTALL_DATA} boincmgr.*.png ${STAGEDIR}${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MSKINS}
	cd ${WRKSRC}/clientgui && ${COPYTREE_SHARE} skins ${STAGEDIR}${DATADIR}
.else
	${MKDIR} ${STAGEDIR}${DATADIR}/skins
	cd ${WRKSRC}/clientgui/skins && ${COPYTREE_SHARE} Default ${STAGEDIR}${DATADIR}/skins
.endif

post-install-X11-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/ttf
	cd ${WRKSRC}/api/ttf/liberation-fonts-ttf-2.00.0 && \
		${INSTALL_DATA} *.ttf ${STAGEDIR}${DATADIR}/ttf

.include <bsd.port.mk>
