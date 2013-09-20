# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	close-all-tabs
PORTVERSION=	1.1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A toolbar button to close all open tabs

XPI_DISTNAME=	close_all_tabs
XPI_ID=		closealltabs@jgadesign.net
XPI_NUM=	2914
XPI_FILES=	chrome/closealltabs.jar chrome.manifest install.rdf
XPI_DIRS=	chrome

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
