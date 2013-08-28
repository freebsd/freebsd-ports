# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-gui
PORTVERSION=	0.23.1
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep GUI library

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
BUILD_DEPENDS+=	texi2pdf:${PORTSDIR}/print/texinfo
.endif
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
BUILD_DEPENDS+=	${LOCALBASE}/lib/libflite.a:${PORTSDIR}/audio/flite

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/lib
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USE_XORG=	x11 xt
NOPORTDOCS=	dvi2pdf broken

EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.patch
EXTRA_PATCHES+=	${FILESDIR}/GNUmakefile.speech.patch
EXTRA_PATCHES+=	${FILESDIR}/AudioOutputSink.m.patch
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BREAKS_IF_PEDANTIC=	yes
PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

ADDITIONAL_INCLUDE_DIRS+=	-I${LOCALBASE}/include/libpng15

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
PLIST_SUB+=	WITH_CUPS=""
.else
PLIST_SUB+=	WITH_CUPS="@comment "
.endif

ASPELL_PORT?=	textproc/aspell
.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/${ASPELL_PORT}
PLIST_SUB+=	WITH_ASPELL=""
.else
PLIST_SUB+=	WITH_ASPELL="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s|libpng/png.h|png.h|" ${WRKSRC}/configure

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile
.endif

.include <bsd.port.mk>
