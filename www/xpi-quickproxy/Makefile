# New ports collection makefile for:	xpi-quickproxy
# Date created:		5 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quickproxy
PORTVERSION=	2008.08.24
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A statusbar button to quickly turn the proxy on and off

DEPRECATED=	Ports could installed and updated more easily by user's browser(firefox)
EXPIRATION_DATE=2009-01-31

XPI_ID=		{d5ea4520-61a1-11da-8cd6-0800200c9a66}
XPI_NUM=	1557
XPI_FILES=	chrome/quickproxy.jar chrome.manifest install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
