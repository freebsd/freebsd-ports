PORTNAME=	Services_Twitter
PORTVERSION=	0.7.0
CATEGORIES=	net www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP interface to Twitter's API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}

USES=		cpe pear php
USE_PHP=	json simplexml mbstring

CPE_VENDOR=	services_twitter_group

.include <bsd.port.mk>
