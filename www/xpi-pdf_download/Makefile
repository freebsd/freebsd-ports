# New ports collection makefile for:	xpi-pdf_download
# Date created:			2 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdf_download
PORTVERSION=	2.2.0.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An extension to handle PDF files

XPI_ID=		{37E4D8EA-8BDA-4831-8EA1-89053939A250}
XPI_NUM=	636
XPI_FILES=	META-INF/manifest.mf META-INF/zigbert.rsa META-INF/zigbert.sf \
		chrome/pdfdownload.jar chrome.manifest install.rdf \
		defaults/preferences/prefs.js
XPI_DIRS=	META-INF chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
