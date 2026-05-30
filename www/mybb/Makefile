PORTNAME=	mybb
DISTVERSION=	1.8.40
CATEGORIES=	www

MAINTAINER=	dnpowers@me.com
COMMENT=	PHP-based bulletin board / discussion forum system
WWW=		https://mybb.com/

LICENSE=	GPLv3

USES=		cpe mysql php:web
USE_GITHUB=	yes
GH_TAGNAME=	${PORTNAME}_${DISTVERSION:S|.||g}
USE_PHP=	gd iconv mysqli xml xsl

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${MV} ${STAGEDIR}${WWWDIR}/inc/settings.php \
		${STAGEDIR}${WWWDIR}/inc/settings.php.sample

.include <bsd.port.mk>
