# New ports collection makefile for:	xpi-unplug
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	unplug
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	An extension to convert embedded plug-ins to html links

XPI_ID=		unplug@compunach
XPI_FILES=	chrome/content/help_flash.html chrome/content/help_flv.html \
		chrome/content/help_playlist.html \
		chrome/content/help_playtext.html \
		chrome/content/help_ram.html chrome/content/help_rm.html \
		chrome/content/help_skim.html chrome/content/overlay.xul \
		chrome/content/pro_ftp.html chrome/content/pro_mms.html \
		chrome/content/pro_other.html chrome/content/pro_rtsp.html \
		chrome/content/settings.xul chrome/content/unplug.js \
		chrome/content/unplug_settings.js chrome/content/zuul.html \
		chrome/skin/config.png chrome/skin/ftp.png \
		chrome/skin/help.png chrome/skin/hexit.png \
		chrome/skin/pagehog.png chrome/skin/unplug.css \
		chrome/skin/unplug.png chrome/skin/unstar0.png \
		chrome/skin/unstar1.png chrome/skin/unstar2.png \
		chrome/skin/unstar3.png chrome/skin/warn.png chrome.manifest \
		defaults/preferences/cn_unplug.js install.rdf
XPI_DIRS=	chrome/content chrome/skin chrome defaults/preferences \
		defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
