# New ports collection makefile for:	xpi-jiwaonwooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	jiwaonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	jiwaonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Jiwa

XPI_ID=		jiwaonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/jiwa.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libjiwa.so install/jiwa.png install/jiwa_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/jiwa/
PLIST_FILES+=	share/wooztalk/plugins/jiwa/libjiwa.so share/wooztalk/plugins/jiwa/jiwa.png \
		share/wooztalk/plugins/jiwa/jiwa_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/jiwa"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/jiwa
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/jiwa
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
