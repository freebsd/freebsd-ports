# Created by: Alexander V. Ribchansky <triosoft@triosoft.com.ua>
# $FreeBSD$

PORTNAME=	imagezoom
PORTVERSION=	0.3.1
DISTVERSIONSUFFIX=	-fx+mz+tb+sm
CATEGORIES=	www
DISTNAME=	image_zoom-${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	Zoom images

XPI_ID=		{1A2D0EC4-75F5-4c91-89C4-3656F6E44B68}
XPI_NUM=	139
XPI_FILES=	chrome/imagezoom.jar defaults/preferences/imagezoom-defaults.js \
		gpl.txt chrome.manifest install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

post-patch:
	@${REINPLACE_CMD} -e '/maxVersion/s|3.0b4|3.0.\*|' ${WRKSRC}/install.rdf
	@${RM} ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
