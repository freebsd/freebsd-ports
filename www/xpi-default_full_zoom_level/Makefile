# New ports collection makefile for:	xpi-default_full_zoom_level
# Date created:				2009-04-17
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	default_full_zoom_level
PORTVERSION=	4.2
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Default Full Zoom Level extention

XPI_NUM=	6965
XPI_ID=		{D9A7CBEC-DE1A-444f-A092-844461596C4D}
XPI_FILES=	chrome.manifest chrome/defaultfullzoomlevel.jar \
		defaults/preferences/defaultfullzoomlevel.js \
		install.rdf license.txt
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
