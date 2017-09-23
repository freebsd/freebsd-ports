# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	modify_headers
PORTVERSION=	0.7.1.2b
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefox extension to manipulate HTTP headers

XPI_NUM=	967
XPI_ID=		{b749fc7c-e949-447f-926c-3f4eed6accfe}

XPI_FILES=	chrome.manifest \
		chrome/content/bindings/bindings.xml \
		chrome/content/contents.rdf \
		chrome/content/disabled.gif \
		chrome/content/enabled.gif \
		chrome/content/export.js \
		chrome/content/exportimport.js \
		chrome/content/exportwizard.xul \
		chrome/content/icons/ModifyHeaders-16.png \
		chrome/content/icons/ModifyHeaders-32.png \
		chrome/content/icons/ModifyHeaders-48.png \
		chrome/content/icons/ModifyHeaders-grey-16.png \
		chrome/content/icons/ModifyHeaders-grey-32.png \
		chrome/content/icons/badge.png \
		chrome/content/icons/bug.png \
		chrome/content/icons/first-aid-kit.png \
		chrome/content/icons/globe.png \
		chrome/content/icons/info.png \
		chrome/content/icons/star.png \
		chrome/content/icons/thumbs-up.png \
		chrome/content/icons/tools.png \
		chrome/content/icons/twitter.png \
		chrome/content/icons/user.png \
		chrome/content/import.js \
		chrome/content/importwizard.xul \
		chrome/content/modifyheaders.css \
		chrome/content/modifyheaders.js \
		chrome/content/preferences-tab.xul \
		chrome/content/preferences.js \
		chrome/content/preferences.xul \
		chrome/content/prefs-about.xul \
		chrome/content/prefs-headers.xul \
		chrome/content/prefs-options.xul \
		chrome/content/toolsOverlay.xul \
		chrome/locale/en-US/modifyheaders.dtd \
		chrome/locale/en-US/modifyheaders.properties \
		components/mhIHeader.xpt \
		components/modifyheaders-autocomplete.js \
		components/modifyheaders-service.js \
		components/nsIModifyheaders.xpt \
		defaults/preferences/defaults.js \
		install.js \
		install.rdf

XPI_DIRS=	chrome/content/bindings \
		chrome/content/icons \
		chrome/content \
		chrome/locale/en-US \
		chrome/locale \
		chrome \
		components \
		defaults/preferences \
		defaults

post-patch:
		@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} \{} \;

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
