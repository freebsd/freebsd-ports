# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-gui
PORTVERSION=	0.24.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	GNUSTEP/core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep GUI library

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

OPTIONS_DEFINE=	DOCS CUPS ASPELL
OPTIONS_DEFAULT=	CUPS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html \
			texi2pdf:print/texinfo

LIB_DEPENDS+=	libtiff.so:graphics/tiff
LIB_DEPENDS+=	libpng.so:graphics/png
LIB_DEPENDS+=	libgif.so:graphics/giflib
LIB_DEPENDS+=	libicui18n.so:devel/icu
LIB_DEPENDS+=	libsndfile.so:audio/libsndfile
LIB_DEPENDS+=	libao.so:audio/libao
BUILD_DEPENDS+=	${LOCALBASE}/lib/libflite.a:audio/flite

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/lib

USES=		gnustep jpeg pkgconfig
USE_GNUSTEP=	base build
USE_XORG=	x11 xt

EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.patch
EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.speech.patch
EXTRA_PATCHES+=	${FILESDIR}/AudioOutputSink.m.patch
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

CUPS_CONFIGURE_ENABLE=		cups
CUPS_LIB_DEPENDS+=	libcups.so:print/cups
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=	aspell

USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

post-patch:
	${REINPLACE_CMD} -e "s|libpng/png.h|png.h|" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>
