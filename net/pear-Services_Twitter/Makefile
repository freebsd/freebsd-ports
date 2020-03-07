# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Services_Twitter
PORTVERSION=	0.7.0
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Twitter's API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}

USES=		pear php
USE_PHP=	json simplexml mbstring

.include <bsd.port.mk>
