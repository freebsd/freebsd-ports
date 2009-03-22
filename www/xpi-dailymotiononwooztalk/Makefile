# New ports collection makefile for:	xpi-dailymotionwooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	dailymotiononwooztalk
PORTVERSION=	0.9.9a
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	dailymotiononwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Dailymotion

XPI_ID=		dailymotiononwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/dailymotion.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libdailymotion.so install/dailymotion.png install/dailymotion_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/dailymotion/
PLIST_FILES+=	share/wooztalk/plugins/dailymotion/libdailymotion.so share/wooztalk/plugins/dailymotion/dailymotion.png \
		share/wooztalk/plugins/dailymotion/dailymotion_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/dailymotion"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/dailymotion
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/dailymotion
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
