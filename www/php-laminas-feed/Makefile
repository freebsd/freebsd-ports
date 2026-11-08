PORTNAME=	laminas-feed
DISTVERSION=	2.26.3
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Create and consume RSS and Atom feeds
WWW=		https://docs.laminas.dev/laminas-feed/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}laminas-escaper>=2.9:www/php-laminas-escaper@${PHP_FLAVOR} \
		${PHP_PKGNAMEPREFIX}laminas-stdlib>=3.6:devel/php-laminas-stdlib@${PHP_FLAVOR}

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	laminas
USE_PHP=	dom filter
IGNORE_WITH_PHP=	86

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pear/Laminas/Feed
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pear/Laminas/Feed)

.include <bsd.port.mk>
