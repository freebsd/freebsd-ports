# New ports collection makefile for:	xpi-xpcom-component-viewer
# Date created:		21 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpcom-component-viewer
PORTVERSION=	0.7.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www
MASTER_SITES=	CENKES

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XPCOM Component Viewer

XPI_DISTNAME=	xpcom_component_viewer
XPI_ID=		{61a6c679-bb38-46b9-9b78-4666b81699ff}
XPI_FILES=	LICENSE.TXT chrome/cview.jar chrome/locale/cview/en-US/contents.rdf \
		chrome/locale/cview/en-US/cviewOverlay.dtd install.rdf chrome.manifest
XPI_DIRS=	chrome/locale/cview/en-US chrome/locale/cview chrome/locale chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
