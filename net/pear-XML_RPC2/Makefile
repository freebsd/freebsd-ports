PORTNAME=	XML_RPC2
PORTVERSION=	1.1.5
CATEGORIES=	net devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML-RPC client/server library

LICENSE=	PHP301

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Cache_Lite>=1.6.0,1:sysutils/pear-Cache_Lite@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}HTTP_Request2>=2.0.0,1:www/pear-HTTP_Request2@${PHP_FLAVOR}

USES=		pear
USE_PHP=	curl

NO_ARCH=	yes

.include <bsd.port.mk>
