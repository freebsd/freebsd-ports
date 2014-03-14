# Created by: jseger@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/print/freetype2/Makefile,v 1.28 2011/10/25 18:31:21 kwm Exp $

PORTNAME=	freetype2
PORTVERSION=	2.5.3
CATEGORIES=	print
MASTER_SITES=	http://savannah.nongnu.org/download/freetype/ \
		SF/freetype/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}/ \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/freetype2/
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Free and portable TrueType font rendering engine

USE_BZIP2=	yes
USES=		gmake
MAKE_ENV=	TOP=""
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	ltverhack:9
ltverhack_PATCH_FILES=	builds/unix/ltmain.sh
CONFIGURE_ARGS=	--without-harfbuzz
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix

OPTIONS_DEFINE=		LCD_FILTERING PNG
LCD_FILTERING_DESC?=	Sub-pixel rendering (patented)
PNG_DESC=		Png compressed OpenType embedded bitmaps support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLCD_FILTERING}
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=--without-png
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/builds/unix/install.mk

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreetype.so.*

.include <bsd.port.mk>
