# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-gui
PORTVERSION=	0.24.0
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep GUI library

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

OPTIONS_DEFINE=	DOCS CUPS ASPELL
OPTIONS_DEFAULT=	CUPS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
			texi2pdf:${PORTSDIR}/print/texinfo

LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	libgif.so:${PORTSDIR}/graphics/giflib
LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile
LIB_DEPENDS+=	libao.so:${PORTSDIR}/audio/libao
BUILD_DEPENDS+=	${LOCALBASE}/lib/libflite.a:${PORTSDIR}/audio/flite

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/lib

USES=		pkgconfig
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USE_XORG=	x11 xt

EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.patch
EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.speech.patch
EXTRA_PATCHES+=	${FILESDIR}/AudioOutputSink.m.patch
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BREAKS_IF_PEDANTIC=	yes

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

ADDITIONAL_INCLUDE_DIRS+=	-I${LOCALBASE}/include/libpng15

CUPS_CONFIGURE_ENABLE=		cups
CUPS_LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_CONFIGURE_ENABLE=	aspell

post-patch:
	${REINPLACE_CMD} -e "s|libpng/png.h|png.h|" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>
