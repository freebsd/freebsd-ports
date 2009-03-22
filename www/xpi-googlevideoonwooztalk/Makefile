# New ports collection makefile for:	xpi-googlevideowooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	googlevideoonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	googlevideoonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Google Video

XPI_ID=		googlevideoonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/googlevideo.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libgooglevideo.so install/googlevideo.png install/googlevideo_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/googlevideo/
PLIST_FILES+=	share/wooztalk/plugins/googlevideo/libgooglevideo.so share/wooztalk/plugins/googlevideo/googlevideo.png \
		share/wooztalk/plugins/googlevideo/googlevideo_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/googlevideo"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/googlevideo
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/googlevideo
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
