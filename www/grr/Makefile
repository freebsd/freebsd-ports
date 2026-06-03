PORTNAME=	grr
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	www gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Grr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rss reader for GNUstep
WWW=		https://gap.nongnu.org/grr/index.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libRSSKit.so:www/rsskit

USES=		gnustep
USE_GNUSTEP=	back build

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Grr \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/ArticleOperations.grrc/ArticleOperations \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/ArticleTable.grrc/ArticleTable \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/ArticleView.grrc/ArticleView \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/DatabaseOperations.grrc/DatabaseOperations \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/DatabaseTreeView.grrc/DatabaseTreeView \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/Fonts.grrc/Fonts \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/Proxy.grrc/Proxy \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/Searching.grrc/Searching \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/SubscriptionPanel.grrc/SubscriptionPanel \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Grr.app/Resources/TreeDatabase.grrdb/TreeDatabase

.include <bsd.port.mk>
