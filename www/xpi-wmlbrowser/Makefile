# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmlbrowser
PORTVERSION=	0.7.28
CATEGORIES=	www
MASTER_SITES=	MOZDEV

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	WML implementation

XPI_ID=		{c4dc572a-3295-40eb-b30f-b54aa4cdc4b7}
XPI_FILES=	chrome/wmlbrowser.jar components/wml-service.js defaults/preferences/prefs.js \
		install.js install.rdf chrome.manifest
XPI_DIRS=	chrome components defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
