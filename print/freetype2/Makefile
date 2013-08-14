# Created by: jseger@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/print/freetype2/Makefile,v 1.28 2011/10/25 18:31:21 kwm Exp $

PORTNAME=	freetype2
PORTVERSION=	2.4.12
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/freetype/${PORTNAME}/${PORTVERSION} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/freetype2/
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A free and portable TrueType font rendering engine

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	TOP=""
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	ltverhack:9
LIBTOOLFILES=	builds/unix/configure
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix

OPTIONS_DEFINE=		LCD_FILTERING CFF_HINTING_ADOBE
LCD_FILTERING_DESC?=	Sub-pixel rendering (patented)
CFF_HINTING_ADOBE_DESC=	CFF parsing and hinting engine by Adobe and Google

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLCD_FILTERING}
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/builds/unix/install.mk
.if ${PORT_OPTIONS:MCFF_HINTING_ADOBE}
	@${REINPLACE_CMD} -e 's|FT_CFF_HINTING_FREETYPE|FT_CFF_HINTING_ADOBE|g' \
		${WRKSRC}/src/cff/cffobjs.c
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/^LIBTOOL/s|LIBTOOL := $$(FT_LIBTOOL_DIR)/libtool|LIBTOOL := ${WRKDIR}/gnome-libtool|' \
	    	${WRKSRC}/builds/unix/unix-cc.in

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

.include <bsd.port.mk>
