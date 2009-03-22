# New ports collection makefile for:	xpi-firefoxonwooztalk
# Date created:		2008-06-13
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	firefoxonwooztalk
PORTVERSION=	0.9.9
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/common/download/
DISTNAME=	firefoxonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors with Firefox

XPI_ID=		firefoxonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf \
		content/contents.rdf content/firefoxOverlay.xul	content/overlay.js \
		locale/en-US/contents.rdf locale/en-US/firefoxonwooztalk.dtd \
		locale/en-US/firefoxonwooztalk.properties locale/fr-FR/contents.rdf \
		locale/fr-FR/firefoxonwooztalk.dtd \
		locale/fr-FR/firefoxonwooztalk.properties skin/disabled.ico \
		skin/enabled.ico skin/overlay.css skin/wooztalk.ico \
		install/firefox.png install/firefox_dis.png install/libfirefox.so

XPI_DIRS=	content locale/en-US locale/fr-FR locale skin install

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
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/firefox
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
