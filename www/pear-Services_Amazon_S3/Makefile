# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Services_Amazon_S3
PORTVERSION=	0.4.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP API for Amazon S3 (Simple Storage Service)

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR} \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR} \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2@${PHP_FLAVOR}

USE_PHP=	spl
USES=		pear php

.include <bsd.port.mk>
