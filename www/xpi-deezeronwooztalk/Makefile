# New ports collection makefile for:	xpi-deezeronwooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	deezeronwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	deezeronwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Deezer

XPI_ID=		deezeronwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/deezer.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libdeezer.so install/deezer.png install/deezer_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/deezer/
PLIST_FILES+=	share/wooztalk/plugins/deezer/libdeezer.so share/wooztalk/plugins/deezer/deezer.png \
		share/wooztalk/plugins/deezer/deezer_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/deezer"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/deezer
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/deezer
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
