PORTNAME=	amule
DISTVERSION=	3.0.0
CATEGORIES=	net-p2p

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	All-platform P2P client based on eMule
WWW=		https://github.com/amule-project/amule

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl \
		libzstd.so:archivers/zstd

USES=		cmake:testing gettext-runtime gnome localbase:ldflags pkgconfig \
		readline
USE_GITHUB=	yes
GH_ACCOUNT=	amule-org
USE_GNOME=	glib20
USE_WX=		3.2
USE_RC_SUBR=	amuled

CMAKE_ON=	BUILD_ALC BUILD_ALCC BUILD_AMULECMD BUILD_DAEMON BUILD_ED2K \
		BUILD_WXCAS
CMAKE_OFF=	BUILD_TESTING HAVE_BFD

OPTIONS_DEFINE=			CAS DOCS FILEVIEW NLS UPNP WEBSERVER
OPTIONS_DEFAULT=		AMULEGUI CAS FILEVIEW MONOLITHIC WEBSERVER
OPTIONS_MULTI=			COMPONENTS
OPTIONS_MULTI_COMPONENTS=	AMULEGUI MONOLITHIC
OPTIONS_SUB=			yes

AMULEGUI_DESC=		Build aMule remote GUI
CAS_DESC=		Build aMule Statistics for console
FILEVIEW_DESC=		Build file viewer for console
MONOLITHIC_DESC=	Build monolithic aMule

AMULEGUI_CMAKE_BOOL=	BUILD_REMOTEGUI

CAS_LIB_DEPENDS=	libgd.so:graphics/gd
CAS_CMAKE_BOOL=		BUILD_CAS

FILEVIEW_CMAKE_BOOL=	BUILD_FILEVIEW

MONOLITHIC_USES=	desktop-file-utils
MONOLITHIC_CMAKE_BOOL=	BUILD_MONOLITHIC

NLS_USES=	gettext-tools
NLS_CMAKE_BOOL=	ENABLE_NLS

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CMAKE_BOOL=	ENABLE_UPNP

WEBSERVER_LIB_DEPENDS=	libpng.so:graphics/png
WEBSERVER_USES=		readline
WEBSERVER_CMAKE_BOOL=	BUILD_WEBSERVER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAMULEGUI} || ${PORT_OPTIONS:MMONOLITHIC}
PLIST_SUB+=	AMULESKIN=""
.else
PLIST_SUB+=	AMULESKIN="@comment "
.endif

# Fix segmentation fault, PR 266866
# See also 5a19c08: ("security/cryptopp: Update to 8.7.0")
.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

.include <bsd.port.mk>
