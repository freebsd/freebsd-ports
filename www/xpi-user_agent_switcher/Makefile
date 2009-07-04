# New ports collection makefile for:	xpi-user_agent_switcher
# Date created:				2009-04-26
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	user_agent_switcher
PORTVERSION=	0.7.2
DISTVERSIONSUFFIX=	-fx+sm
CATEGORIES=	www

MAINTAINER=	nork@FreeBSD.org
COMMENT=	The User Agent Switcher extension

XPI_NUM=	59
XPI_ID=		{e968fc70-8f95-4ab9-9e79-304de2a71ee1}
XPI_FILES=	chrome.manifest \
		chrome/useragentswitcher.jar \
		install.js install.rdf \
		license.txt
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
