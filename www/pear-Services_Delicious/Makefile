# Created by: chinsan <chisnan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Services_Delicious
PORTVERSION=	0.6.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Client for the del.icio.us web service

BUILD_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer@${PHP_FLAVOR} \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer@${PHP_FLAVOR} \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}

USES=		dos2unix pear php
USE_PHP=	openssl

.include <bsd.port.mk>
