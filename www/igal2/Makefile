# Created by: gahr
# $FreeBSD$

PORTNAME=	igal2
PORTVERSION=	2.1
CATEGORIES=	www graphics
MASTER_SITES=	http://igal.trexler.at/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A simple CLI image gallery generator

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

OPTIONS_DEFINE=	EXIF
EXIF_DESC=	Support EXIF data (-e option)

CONFLICTS=	igal-1.*
USES=		perl5
NO_BUILD=	yes

MAN1=		igal2.1
MANCOMPRESSED=	no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIF}
RUN_DEPENDS+=	 p5-Image-ExifTool>=7.0:${PORTSDIR}/graphics/p5-Image-ExifTool
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile ${WRKSRC}/igal2

.include <bsd.port.mk>
