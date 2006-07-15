# New ports collection makefile for:	xpi-joga
# Date created:		16 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	joga
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_CSME}
# The unversioned dist is at http://dl.google.com/firefox/joga/companion.xpi
# The update RDF is at http://tools.google.com/firefox/joga/update.rdf

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Joga.com Companion

XPI_ID=		{06108483-1773-402e-a112-bfec19a73942}
XPI_FILES=	META-INF/manifest.mf META-INF/zigbert.rsa META-INF/zigbert.sf chrome/joga.jar \
		chrome.manifest defaults/preferences/joga.js install.rdf
XPI_DIRS=	META-INF chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
