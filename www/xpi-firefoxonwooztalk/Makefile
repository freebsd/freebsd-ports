# New ports collection makefile for:	xpi-wooztalk
# Date created:		2008-06-13
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	firefoxonwooztalk
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/common/download/
DISTNAME=	firefoxonwooztalk_v0.9.8d-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors with Firefox

XPI_ID=		firefoxonwooztalk@kurioos-itech.com
XPI_FILES=	chrome.manifest install.rdf \
		content/contents.rdf content/firefoxOverlay.xul	content/overlay.js \
		locale/en-US/contents.rdf locale/en-US/firefoxonwooztalk.dtd \
		locale/en-US/firefoxonwooztalk.properties locale/fr-FR/contents.rdf \
		locale/fr-FR/firefoxonwooztalk.dtd \
		locale/fr-FR/firefoxonwooztalk.properties skin/disabled.ico \
		skin/enabled.ico skin/overlay.css skin/wooztalk.ico \
		plugins/libfirefox.so plugins/firefox.png plugins/firefox_dis.png

XPI_DIRS=	content locale/en-US locale/fr-FR locale skin plugins

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/firefox/
PLIST_FILES+=	share/wooztalk/plugins/firefox/libfirefox.so share/wooztalk/plugins/firefox/firefox.png \
		share/wooztalk/plugins/firefox/firefox_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/firefox"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/firefox
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${PREFIX}/share/wooztalk/plugins/firefox
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
