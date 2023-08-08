PORTNAME=	Services_Amazon_S3
PORTVERSION=	0.4.0
CATEGORIES=	www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP API for Amazon S3 (Simple Storage Service)
WWW=		https://pear.php.net/package/Services_Amazon_S3

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR} \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR} \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
