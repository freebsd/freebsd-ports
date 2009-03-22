# New ports collection makefile for:	xpi-lastfmwooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	lastfmonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	lastfmonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Last.fm

XPI_ID=		lastfmonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/lastfm.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/liblastfm.so install/lastfm.png install/lastfm_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/lastfm/
PLIST_FILES+=	share/wooztalk/plugins/lastfm/liblastfm.so share/wooztalk/plugins/lastfm/lastfm.png \
		share/wooztalk/plugins/lastfm/lastfm_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/lastfm"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/lastfm
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/lastfm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
