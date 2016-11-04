# Created by: chinsan <chisnan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Services_Delicious
PORTVERSION=	0.6.0
CATEGORIES=	www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR Client for the del.icio.us web service

BUILD_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request
RUN_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request

USES=		dos2unix pear
USE_PHP=	openssl

.include <bsd.port.mk>
