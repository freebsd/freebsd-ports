# Created by: Alexander V. Ribchansky <triosoft@triosoft.com.ua>
# $FreeBSD$

PORTNAME=	tabextensions
PORTVERSION=	2.1.2006031301
DISTVERSIONSUFFIX=	ru-RU_en
CATEGORIES=	russian www
MASTER_SITES=	http://people.mozilla.ru/lautour/
PKGNAMESUFFIX=	-ru
DISTNAME=	${PORTNAME}_${PORTVERSION}-${DISTVERSIONSUFFIX}

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	Improves tabbed browsing

CONFLICTS=	xpi-tabextensions-[0-9]*

USE_XPI=	*firefox*
XPI_ID=		{0B0B0DA8-08BA-4bc6-987C-6BC9F4D8A81E}
XPI_FILES=	chrome/tabextensions.jar chrome.manifest install.js install.rdf \
		locale.inf options.inf
XPI_DIRS=	chrome

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
