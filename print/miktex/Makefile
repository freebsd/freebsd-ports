PORTNAME=	miktex
DISTVERSION=	23.9
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	https://miktex.org/download/ctan/systems/win32/miktex/source/ \
	https://ctan.org/tex-archive/systems/win32/miktex/tm/packages/:bootstrap
DISTFILES=	miktex-zzdb1-2.9.tar.lzma:bootstrap \
		miktex-zzdb3-2.9.tar.lzma:bootstrap \
		miktex-config-2.9.tar.lzma:bootstrap \
		miktex-dvips.tar.lzma:bootstrap \
		miktex-fontconfig.tar.lzma:bootstrap \
		miktex-misc.tar.lzma:bootstrap \
		tetex.tar.lzma:bootstrap \
		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	miktex
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of TeX/LaTeX
WWW=		https://miktex.org

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
		libinotify.so:devel/libinotify \
		liblog4cxx.so:devel/log4cxx \
		libmpfr.so:math/mpfr \
		libmspack.so:archivers/libmspack \
		libpng.so:graphics/png \
		libpopt.so:devel/popt \
		liburiparser.so:net/uriparser \
		libzzip.so:devel/zziplib

USES=		bison cmake:noninja gettext-tools gmake gnome jpeg pkgconfig ssl tar:xz xorg
USE_GNOME=	cairo libxslt
USE_LDCONFIG=	yes
USE_XORG=	pixman

CMAKE_ARGS=	-DMIKTEX_SYSTEM_ETC_FONTS_CONFD_DIR=${LOCALBASE}/etc/fonts/conf.d \
		-DMIKTEX_SYSTEM_VAR_CACHE_DIR=${DATADIR}/cache \
		-DMIKTEX_SYSTEM_VAR_LIB_DIR=${DATADIR}/lib

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		MANPAGES UIQT
OPTIONS_DEFAULT=	MANPAGES UIQT
OPTIONS_SUB=		yes

UIQT_DESC=	Build Qt components

MANPAGES_CMAKE_BOOL=	WITH_MAN_PAGES
UIQT_USES=	gl
UIQT_USES=	desktop-file-utils qt:5
UIQT_USE=	qt=buildtools:build,concurrent,core,dbus,declarative,gui,linguisttools,network,printsupport,qmake:build,script,scripttools,uitools,widgets,xml gl=gl
UIQT_CMAKE_BOOL=	WITH_UI_QT

post-extract:
	${MKDIR} ${BUILD_WRKSRC}
.	for f in ${DISTFILES:M*bootstrap}
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${f:S/:bootstrap//} ${BUILD_WRKSRC}
.	endfor

post-patch:
	${REINPLACE_CMD} 's|log4cxx/rollingfileappender.h|log4cxx/rolling/rollingfileappender.h|g' \
		${WRKSRC}/Libraries/MiKTeX/App/app.cpp \
		${WRKSRC}/Programs/Editors/TeXworks/miktex/miktex-texworks.cpp \
		${WRKSRC}/Programs/MiKTeX/Console/Qt/main.cpp \
		${WRKSRC}/Programs/MiKTeX/PackageManager/mpm/mpm.cpp \
		${WRKSRC}/Programs/MiKTeX/Yap/MFC/StdAfx.h \
		${WRKSRC}/Programs/MiKTeX/initexmf/initexmf.cpp \
		${WRKSRC}/Programs/MiKTeX/miktex/miktex.cpp

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/miktex-texmf/miktex/config/*.log

.include <bsd.port.mk>
