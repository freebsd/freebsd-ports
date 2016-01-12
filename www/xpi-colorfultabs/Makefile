# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colorfultabs
PORTVERSION=	29.7
DISTVERSIONSUFFIX=	-sm+fx
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Colors every tab in a different color

XPI_ID=		{0545b830-f0aa-4d7e-8820-50a4629a56fe}
XPI_NUM=	1368

xpi-post-extract:
	@${FIND} ${WRKSRC} -name .DS_Store -delete

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
