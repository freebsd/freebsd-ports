# New ports collection makefile for:	xpi-imeemwooztalk
# Date created:		2009-03-09
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	imeemonwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	imeemonwooztalk-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors on Imeem

XPI_ID=		imeemonwooztalk@wooztalk.com
XPI_FILES=	chrome.manifest install.rdf chrome/content/imeem.png \
		chrome/content/overlay.xul chrome/content/overlay.js \
		install/libimeem.so install/imeem.png install/imeem_dis.png

XPI_DIRS=	chrome/content chrome install

.include "../xpi-adblock/Makefile.xpi"

USE_LDCONFIG+=	${PREFIX}/share/wooztalk/plugins/imeem/
PLIST_FILES+=	share/wooztalk/plugins/imeem/libimeem.so share/wooztalk/plugins/imeem/imeem.png \
		share/wooztalk/plugins/imeem/imeem_dis.png
PLIST_FILES+=	"@dirrm share/wooztalk/plugins/imeem"
PLIST_FILES+=	"@dirrmtry share/wooztalk/plugins"
PLIST_FILES+=	"@dirrmtry share/wooztalk/"

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/wooztalk
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/imeem
	@${INSTALL_DATA} ${WRKSRC}/install/* ${PREFIX}/share/wooztalk/plugins/imeem
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
