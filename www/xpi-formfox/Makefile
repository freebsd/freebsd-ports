# New ports collection makefile for:	xpi-formfox
# Date created:		21 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	formfox
PORTVERSION=	1.6.2
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An extension to display form's action

XPI_NUM=	1579
XPI_ID=		formfox@daniel.steinbrook
XPI_FILES=	chrome/formfox.jar defaults/preferences/prefs.js install.rdf \
		chrome.manifest
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
