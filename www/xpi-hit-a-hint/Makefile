# New ports collection makefile for:	xpi-hit-a-hint
# Date created:		2006-07-15
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	hit-a-hint
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Click links by hitting hints

XPI_ID=		{4476fef4-3557-40b5-afcd-d6903cf7cc9d}
XPI_FILES=	chrome/chrome.jar chrome.manifest defaults/preferences/prefs.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
