# New ports collection makefile for:	xpi-vimeowooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	vimeoonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	vimeoonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Vimeo

XPI_ID=		vimeoonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/vimeo.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libvimeo.so install/vimeo.png install/vimeo_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/vimeo/
PLIST_FILES+=	share/wooztalk/plugins/vimeo/libvimeo.so share/wooztalk/plugins/vimeo/vimeo.png \
		share/wooztalk/plugins/vimeo/vimeo_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/vimeo"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/vimeo
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/vimeo
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
