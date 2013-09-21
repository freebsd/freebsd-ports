# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	it_s_all_text
PORTVERSION=	1.8.1
DISTVERSIONSUFFIX=	-sm+fx
CATEGORIES=	www
DISTNAME=	${PORTNAME:S/it_s/its/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Edit textareas using an external editor

XPI_NUM=	4125
XPI_ID=		itsalltext@docwhat.gerf.org
XPI_FILES=	chrome.manifest \
		defaults/preferences/itsalltext.js \
		gpl.txt install.rdf
XPI_DIRS=	chrome \
		defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
