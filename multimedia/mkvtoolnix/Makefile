PORTNAME=	mkvtoolnix
PORTVERSION=	77.0
CATEGORIES=	multimedia audio
MASTER_SITES=	https://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		https://mkvtoolnix.download/sources/

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams
WWW=		https://www.bunkus.org/videotools/mkvtoolnix/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	does not install

BUILD_DEPENDS=	rake:devel/rubygem-rake \
		docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libebml.so:textproc/libebml \
		libboost_regex.so:devel/boost-libs \
		libpugixml.so:textproc/pugixml \
		libmatroska.so:multimedia/libmatroska \
		libcmark.so:textproc/cmark \
		libgmp.so:math/gmp

FLAVORS=	qt5 nogui
FLAVOR?=	${FLAVORS:[1]}
nogui_PKGNAMESUFFIX=	-nogui
nogui_CONFLICTS_INSTALL=mkvtoolnix
qt5_CONFLICTS_INSTALL=	mkvtoolnix-nogui

USES=		${_USES_${FLAVOR}}
USE_QT=		${_USE_QT_${FLAVOR}}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE} \
		--with-docbook-xsl-root=${PREFIX}/share/xsl/docbook \
		--disable-qt6 ${_CONFIGURE_ARGS_${FLAVOR}}
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
_USES_qt5=		compiler:c++17-lang desktop-file-utils iconv localbase \
			pkgconfig qmake:no_env qt:5 shared-mime-info tar:xz
_USE_QT_qt5=		buildtools:build concurrent core dbus declarative gui \
			linguisttools:build multimedia network svg widgets
_PLIST_SUB_qt5=		GUI=
_CONFIGURE_ARGS_nogui=	--disable-gui
_USES_nogui=		compiler:c++17-lang iconv localbase pkgconfig qmake:no_env \
			qt:5 tar:xz
_USE_QT_nogui=		buildtools:build core linguisttools:build \
			multimedia:build
_PLIST_SUB_nogui=	GUI="@comment "

PLIST_SUB+=		${_PLIST_SUB_${FLAVOR}}

# Options handling
OPTIONS_DEFINE=	DVDREAD FLAC NLS MANTRANS
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
