PORTNAME=	google-api-php-client
PORTVERSION=	2.12.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	contato@kanazuchi.com
COMMENT=	Google api client for php
WWW=		https://github.com/googleapis/google-api-php-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}composer>=0:devel/php-composer@${PHP_FLAVOR}

USES=	php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	googleapis

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} src ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${WRKSRC}/composer.json ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
