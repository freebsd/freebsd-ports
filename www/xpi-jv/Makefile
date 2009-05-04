# New ports collection makefile for:	xpi-jv
# Date created:				2009-04-26
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jv
PORTVERSION=	0.50
PORTREVISION=	1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A lightweight vim-like editor for textareas

XPI_NUM=	8529
XPI_ID=		jv@eric.uhrhane
XPI_FILES=	chrome.manifest chrome/jv.jar \
		defaults/preferences/prefs.js \
		install.rdf \
		jv@eric.uhrhane/chrome.manifest \
		jv@eric.uhrhane/content/about.js \
		jv@eric.uhrhane/content/about.xul \
		jv@eric.uhrhane/content/jv.js \
		jv@eric.uhrhane/content/overlay.js \
		jv@eric.uhrhane/content/overlay.xul \
		jv@eric.uhrhane/content/queue.js \
		jv@eric.uhrhane/content/settings.js \
		jv@eric.uhrhane/content/settings.xul \
		jv@eric.uhrhane/content/sharedsettings.js \
		jv@eric.uhrhane/content/util.js \
		jv@eric.uhrhane/defaults/preferences/prefs.js \
		jv@eric.uhrhane/install.rdf \
		jv@eric.uhrhane/locale/en-US/about.dtd \
		jv@eric.uhrhane/locale/en-US/overlay.dtd \
		jv@eric.uhrhane/locale/en-US/settings.dtd \
		jv@eric.uhrhane/skin/about.css \
		jv@eric.uhrhane/skin/about.png \
		jv@eric.uhrhane/skin/overlay.css \
		jv@eric.uhrhane/skin/settings.css \
		jv@eric.uhrhane/skin/statusbar-active.png \
		jv@eric.uhrhane/skin/statusbar-inactive.png \
		jv@eric.uhrhane/skin/statusbar-locally-inactive.png \
		jv@eric.uhrhane/skin/statusbar-other.png
XPI_DIRS=	chrome \
		defaults/preferences defaults \
		jv@eric.uhrhane/content \
		jv@eric.uhrhane/defaults/preferences \
		jv@eric.uhrhane/defaults \
		jv@eric.uhrhane/locale/en-US \
		jv@eric.uhrhane/locale \
		jv@eric.uhrhane/skin \
		jv@eric.uhrhane

post-extract:
	@${RM} ${WRKSRC}/jv@eric.uhrhane/.install.rdf.swp

post-patch:
	@${REINPLACE_CMD} \
		-e "/em:maxVersion/s/3\.5b4pre/3.5/" \
			${WRKSRC}/install.rdf
	@${RM} ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
