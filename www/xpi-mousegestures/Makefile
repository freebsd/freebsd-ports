# New ports collection makefile for:	mouse_gestures
# Date created:		2006-05-16
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	mousegestures
PORTVERSION=	1.5.2
DISTVERSIONSUFFIX=	-fx+mz+zm+tb
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Allows you to execute common commands using mouse gestures

XPI_DISTNAME=	mouse_gestures
XPI_NUM=	39
XPI_ID=		{FFA36170-80B1-4535-B0E3-A4569E497DD0}
XPI_FILES=	chrome/mozgest.jar chrome.manifest components/mgIMouseService.xpt \
		install/install.properties install.js install.rdf
XPI_DIRS=	chrome components install

xpi-post-extract:
	@${RM} -rf ${WRKSRC}/platform

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
