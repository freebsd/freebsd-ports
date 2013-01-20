# Created by: Barbara Guida <bar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	server_spy
PORTVERSION=	0.2.1
DISTVERSIONSUFFIX=	-fx
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Indicates what brand of HTTP server runs on the visited site

USE_XPI=	*firefox*

XPI_ID=		ServerSpy@jacquet.eu.org
XPI_NUM=	2036
XPI_FILES=	defaults/preferences/prefs.js \
		chrome/chromeFiles/locale/fr-FR/ui.properties \
		chrome/chromeFiles/locale/fr-FR/ui.ent \
		chrome/chromeFiles/locale/fr-FR/contents.rdf \
		chrome/chromeFiles/locale/en-US/ui.properties \
		chrome/chromeFiles/locale/en-US/ui.ent \
		chrome/chromeFiles/locale/en-US/contents.rdf \
		chrome/chromeFiles/content/unknown.png \
		chrome/chromeFiles/content/statusbar.xul \
		chrome/chromeFiles/content/serverspy.js \
		chrome/chromeFiles/content/serverspy-32.png \
		chrome/chromeFiles/content/overlay.xul \
		chrome/chromeFiles/content/options.xul \
		chrome/chromeFiles/content/n.png \
		chrome/chromeFiles/content/addonbar.xul \
		chrome/chromeFiles/content/about.xul \
		chrome/chromeFiles/content/L.png \
		chrome/chromeFiles/content/I.png \
		chrome/chromeFiles/content/G.png \
		chrome/chromeFiles/content/A.png \
		chrome.manifest \
		install.rdf

XPI_DIRS=	defaults/preferences defaults \
		chrome/chromeFiles/locale/fr-FR \
		chrome/chromeFiles/locale/en-US \
		chrome/chromeFiles/locale \
		chrome/chromeFiles/content chrome/chromeFiles chrome

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>4\.0b8pre<|<em:maxVersion>99.*<|' \
	    ${WRKSRC}/install.rdf

pre-install:
	@${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
