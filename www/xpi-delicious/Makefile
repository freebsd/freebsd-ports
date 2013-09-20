# Created by: Lapo Luchini <lapo@lapo.it>
# $FreeBSD$

PORTNAME=	delicious
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lapo@lapo.it
COMMENT=	An extension to ease the use of del.icio.us remote bookmarks

XPI_ID=		{3c2f3d50-ec4f-11d8-9669-0800200c9a66}
XPI_FILES=	chrome/delicious.jar defaults/preferences/delicious.js install.rdf chrome.manifest
XPI_DIRS=	chrome defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
