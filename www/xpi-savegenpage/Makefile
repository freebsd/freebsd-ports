# New ports collection makefile for:	xpi-savegenpage
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	savegenpage
PORTVERSION=	2006.03.20
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Save Javascript Generated/Rendered HTML Pages

XPI_ID=		{d70d11c0-ff1e-11d9-8cd6-0800200c9a66}
XPI_FILES=	chrome/Io.js chrome/contents.rdf chrome/overlay.xul chrome.manifest \
		defaults/preferences/user.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
