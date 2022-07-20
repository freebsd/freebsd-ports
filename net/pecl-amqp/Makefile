PORTNAME=	amqp
PORTVERSION=	1.10.2
CATEGORIES=	net pear

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PHP extension for AMQP API

# Remove these once upgraded to 1.11.0
DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c-devel

USES=		php:pecl localbase
IGNORE_WITH_PHP=	80 81 82

.include <bsd.port.mk>
