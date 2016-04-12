# Created by: gahr
# $FreeBSD$

PORTNAME=	igal2
PORTVERSION=	2.1
CATEGORIES=	www graphics
MASTER_SITES=	http://igal.trexler.at/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple CLI image gallery generator

LICENSE=	GPLv2

RUN_DEPENDS=	convert:graphics/ImageMagick

OPTIONS_DEFINE=	EXIF
EXIF_DESC=	Support EXIF data (-e option)

CONFLICTS=	igal-1.*
USES=		perl5
NO_BUILD=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIF}
RUN_DEPENDS+=	 p5-Image-ExifTool>=7.0:graphics/p5-Image-ExifTool
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LIBDIR%%|${PREFIX}/lib/igal2|' ${WRKSRC}/igal2

post-install:
	${LN} -sf igal2 ${STAGEDIR}${PREFIX}/bin/igal

.include <bsd.port.mk>
