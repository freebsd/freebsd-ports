# Created by: gahr
# $FreeBSD$

PORTNAME=	igal2
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	www graphics
MASTER_SITES=	http://igal.trexler.at/

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Simple CLI image gallery generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	igal-1.*

USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}

OPTIONS_DEFINE=	EXIF
EXIF_DESC=	Support EXIF data (-e option)
OPTIONS_RADIO=	IMAGICK
OPTIONS_RADIO_IMAGICK=IMAGICK_NOX11 IMAGICK_X11
OPTIONS_DEFAULT=IMAGICK_NOX11
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
IMAGICK_NOX11_DESC=Without X11 support
IMAGICK_X11_DESC=With X11 support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAGICK_X11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
.endif

.if ${PORT_OPTIONS:MIMAGICK_NOX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6-nox11
.endif

EXIF_RUN_DEPENDS=	p5-Image-ExifTool>=7.0:graphics/p5-Image-ExifTool

post-patch:
	${REINPLACE_CMD} -e 's|%%LIBDIR%%|${PREFIX}/lib/igal2|' ${WRKSRC}/igal2

post-install:
	${LN} -sf igal2 ${STAGEDIR}${PREFIX}/bin/igal

.include <bsd.port.post.mk>
