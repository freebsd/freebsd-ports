# New ports collection makefile for:	xpi-clearfields
# Date created:		20 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearfields
PORTVERSION=	3.0.1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Toolbar buttons that clear input fields

DEPRECATED=	Ports could installed and updated more easily by user's browser(firefox)
EXPIRATION_DATE=2009-01-31

XPI_DISTNAME=	clear_fields
XPI_ID=		clearfields@alex.alexander.googlepages.com
XPI_NUM=	2408
XPI_FILES=	chrome/clearfields.jar chrome.manifest install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
