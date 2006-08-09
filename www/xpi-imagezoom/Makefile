# New ports collection makefile for:	xpi-imagezoom
# Date created:		23 May 2006
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$
#

PORTNAME=	imagezoom
PORTVERSION=	0.2.7
CATEGORIES=	www
MASTER_SITES=	http://imagezoom.yellowgorilla.net/ CSME
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	Zoom images

CONFLICTS=	xpi-imagezoom-ru-[0-9]*
XPI_ID=		{1A2D0EC4-75F5-4c91-89C4-3656F6E44B68}
XPI_FILES=	chrome/imagezoom.jar defaults/preferences/imagezoom-defaults.js \
		gpl.txt chrome.manifest install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
