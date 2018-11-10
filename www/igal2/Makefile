# Created by: gahr
# $FreeBSD$

PORTNAME=	igal2
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	http://igal.trexler.at/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple CLI image gallery generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	convert:graphics/ImageMagick6

CONFLICTS=	igal-1.*
USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}

OPTIONS_DEFINE=	EXIF
EXIF_DESC=	Support EXIF data (-e option)
EXIF_RUN_DEPENDS=	p5-Image-ExifTool>=7.0:graphics/p5-Image-ExifTool

post-patch:
	${REINPLACE_CMD} -e 's|%%LIBDIR%%|${PREFIX}/lib/igal2|' ${WRKSRC}/igal2

post-install:
	${LN} -sf igal2 ${STAGEDIR}${PREFIX}/bin/igal

.include <bsd.port.mk>
