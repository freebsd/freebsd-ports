# New ports collection makefile for:	xpi-stumbleupon
# Date created:			4 May 2006
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	stumbleupon
PORTVERSION=	3.64
DISTVERSIONSUFFIX=	-fx+sm+mz
CATEGORIES=	www

MAINTAINER=	lapo@lapo.it
COMMENT=	A collaborative surfing tool extension

LICENSE=	MPL

XPI_NUM=	138
XPI_ID=		{AE93811A-5C9A-4d34-8462-F7B864FC4696}
XPI_FILES=	chrome/stumbleupon.jar chrome.manifest components/stumbleuponService.js install.js install.rdf
XPI_DIRS=	chrome components

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
