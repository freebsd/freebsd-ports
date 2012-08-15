# New ports collection makefile for:	xpi-default_full_zoom_level
# Date created:				2009-04-17
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	default_full_zoom_level
PORTVERSION=	4.3
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Default Full Zoom Level extension

XPI_NUM=	6965
XPI_ID=		{D9A7CBEC-DE1A-444f-A092-844461596C4D}
XPI_FILES=	chrome.manifest chrome/defaultfullzoomlevel.jar \
		defaults/preferences/defaultfullzoomlevel.js \
		install.rdf license.txt
XPI_DIRS=	chrome defaults/preferences defaults

REINPLACE_ARGS=	-i ""

post-patch:
	@${REINPLACE_CMD} '/em:maxVersion/s/"[^"][^"]*"/"3.6.*"/' ${WRKSRC}/install.rdf

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
