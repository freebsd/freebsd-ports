# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fasterfox
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance and network tweaks for Firefox

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

XPI_NUM=	1269
XPI_ID=		{c36177c0-224a-11da-8cd6-0800200c9a66}
XPI_FILES=	chrome/fasterfox.jar chrome.manifest defaults/preferences/fasterfox.js \
		install.rdf readme.txt
XPI_DIRS=	chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
