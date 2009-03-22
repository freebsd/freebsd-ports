# New ports collection makefile for:	xpi-youtubewooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	youtubeonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	youtubeonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Youtube

XPI_ID=		youtubeonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/youtube.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libyoutube.so install/youtube.png install/youtube_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/youtube/
PLIST_FILES+=	share/wooztalk/plugins/youtube/libyoutube.so share/wooztalk/plugins/youtube/youtube.png \
		share/wooztalk/plugins/youtube/youtube_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/youtube"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/youtube
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/youtube
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
