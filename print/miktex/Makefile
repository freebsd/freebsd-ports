# $FreeBSD$

PORTNAME=	miktex
DISTVERSION=	21.2
CATEGORIES=	print
MASTER_SITES=	LOCAL/arrowd/miktex:bootstrap
DISTFILES=	miktex-zzdb1-2.9.tar.lzma:bootstrap \
		miktex-zzdb3-2.9.tar.lzma:bootstrap \
		miktex-config-2.9.tar.lzma:bootstrap \
		miktex-dvips.tar.lzma:bootstrap \
		miktex-fontconfig.tar.lzma:bootstrap \
		miktex-misc.tar.lzma:bootstrap \
		tetex.tar.lzma:bootstrap
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Implementation of TeX/LaTeX

LICENSE=	MULTIPLE
LICENSE_NAME=	Multiple
LICENSE_TEXT=	This is a collection of many independent packages and does not have a single license
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libboost_locale.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi \
		libgd.so:graphics/gd \
		libgmp.so:math/gmp \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libhunspell-1.7.so:textproc/hunspell \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		liblog4cxx.so:devel/log4cxx \
		libmpfr.so:math/mpfr \
		libmspack.so:archivers/libmspack \
		libpng16.so:graphics/png \
		libpopt.so:devel/popt \
		liburiparser.so:net/uriparser \
		libzzip.so:devel/zziplib

USES=		bison cmake:noninja gettext-tools gmake gnome jpeg pkgconfig ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	MiKTeX

USE_XORG=	pixman
USE_GNOME=	cairo libxslt
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		MANPAGES UIQT
OPTIONS_DEFAULT=	MANPAGES UIQT
OPTIONS_SUB=		yes

CONTEXT_DESC=	Enable ConTeXt support
UIQT_DESC=	Build Qt components

MANPAGES_CMAKE_BOOL=	WITH_MAN_PAGES
UIQT_CMAKE_BOOL=	WITH_UI_QT

UIQT_USES=	qt:5 gl
UIQT_USE=	qt=core,concurrent,dbus,gui,linguisttools,printsupport,script,scripttools,uitools,widgets,xml,buildtools_build,qmake_build gl=gl

CMAKE_ARGS=	-DMIKTEX_SYSTEM_ETC_FONTS_CONFD_DIR=${LOCALBASE}/etc/fonts/conf.d \
		-DMIKTEX_SYSTEM_VAR_CACHE_DIR=${DATADIR}/cache \
		-DMIKTEX_SYSTEM_VAR_LIB_DIR=${DATADIR}/lib

DIST_SUBDIR=	miktex

post-extract:
	${MKDIR} ${BUILD_WRKSRC}
.	for f in ${DISTFILES:M*bootstrap}
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${f:S/:bootstrap//} ${BUILD_WRKSRC}
.	endfor

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/miktex-texmf/miktex/config/*.log

.include <bsd.port.mk>
