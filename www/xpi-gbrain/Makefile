# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gbrain
PORTVERSION=	0.5.4
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keeps your browser history at Google bookmarks

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

XPI_NUM=	2515
XPI_ID=		gbrain@andreas.gohr
XPI_FILES=	chrome/gbrain.jar chrome.manifest defaults/preferences/gbrain.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
