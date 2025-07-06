PORTNAME=	mkvtoolnix
PORTVERSION=	93.0
CATEGORIES=	multimedia audio
MASTER_SITES=	https://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		https://mkvtoolnix.download/sources/

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams
WWW=		https://www.bunkus.org/videotools/mkvtoolnix/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	fails to build: IO::TimeoutError: Blocking operation timed out!

BUILD_DEPENDS=	rake:devel/rubygem-rake \
		docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libebml.so:textproc/libebml \
		libboost_system.so:devel/boost-libs \
		libpugixml.so:textproc/pugixml \
		libmatroska.so:multimedia/libmatroska \
		libcmark.so:textproc/cmark \
		libgmp.so:math/gmp

FLAVORS=	qt6 nogui
FLAVOR?=	${FLAVORS:[1]}
nogui_PKGNAMESUFFIX=	-nogui
nogui_CONFLICTS_INSTALL=mkvtoolnix
qt6_CONFLICTS_INSTALL=	mkvtoolnix-nogui

USES=		${_USES_${FLAVOR}}
USE_GL=		${_USE_GL_${FLAVOR}}
USE_QT=		${_USE_QT_${FLAVOR}}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-boost=${LOCALBASE} \
		--with-docbook-xsl-root=${PREFIX}/share/xsl/docbook \
		${_CONFIGURE_ARGS_${FLAVOR}}
MAKE_ENV=	V=1
MAKE_CMD=	rake -v
MAKEFILE=	Rakefile
ALL_TARGET=	#Empty

BINARY_ALIAS=	qmake=${QMAKE} \
		lconvert=${LCONVERT} \
		moc=${MOC} \
		rcc=${RCC} \
		uic=${UIC}

# Flavor handling
_USES_qt6=		compiler:c++20-lang desktop-file-utils gl iconv localbase \
			pkgconfig qmake:no_env qt:6 shared-mime-info tar:xz
_USE_GL_qt6=		gl opengl
_USE_QT_qt6=		base declarative multimedia svg tools
_PLIST_SUB_qt6=		GUI=
_CONFIGURE_ARGS_nogui=	--disable-gui
_USES_nogui=		compiler:c++20-lang iconv localbase pkgconfig qmake:no_env \
			qt:6 tar:xz
_USE_QT_nogui=		base multimedia svg tools:build
_PLIST_SUB_nogui=	GUI="@comment "

PLIST_SUB+=		${_PLIST_SUB_${FLAVOR}}

# Options handling
OPTIONS_DEFINE=	DVDREAD FLAC NLS MANTRANS GUI
OPTIONS_DEFAULT=	FLAC
OPTIONS_SUB=	yes

DVDREAD_DESC=		Support reading DVD chapters via libdvdread
DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_WITH=	dvdread

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_WITH=	flac

NLS_USES=	gettext
NLS_CONFIGURE_WITH=	gettext

MANTRANS_DESC=		Build and install manpage translations
MANTRANS_BUILD_DEPENDS=	po4a:textproc/po4a

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} != clang
USE_CXXSTD=	c++17
.endif

.include <bsd.port.post.mk>
