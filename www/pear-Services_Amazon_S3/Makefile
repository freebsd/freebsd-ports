# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Services_Amazon_S3
PORTVERSION=	0.4.0
CATEGORIES=	www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHP API for Amazon S3 (Simple Storage Service)

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2 \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2 \
		${PEARDIR}/Crypt/HMAC2.php:security/pear-Crypt_HMAC2

USE_PHP=	spl
USES=	pear

.include <bsd.port.mk>
