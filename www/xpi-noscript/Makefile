# New ports collection makefile for:	xpi-noscript
# Date created:		28 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	noscript
PORTVERSION=	1.10
DISTVERSIONSUFFIX=	-fx+sm+fn
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A security-enhancing Java/JS filtering extension

XPI_ID=		{73a6fe31-595d-460b-a920-fcc0f8843232}
XPI_NUM=	722
XPI_FILES=	GPL.txt NoScript_License.txt chrome/noscript.jar chrome.manifest \
		components/noscriptService.js defaults/preferences/noscript.js \
		install.js install.rdf .autoreg mozilla.cfg META-INF/zigbert.rsa META-INF/manifest.mf META-INF/zigbert.sf
XPI_DIRS=	chrome components defaults/preferences defaults META-INF

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
