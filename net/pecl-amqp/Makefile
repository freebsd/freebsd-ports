PORTNAME=	amqp
PORTVERSION=	2.1.1
CATEGORIES=	net pear

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PHP extension for AMQP API
WWW=		https://pecl.php.net/package/amqp

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c

USES=		php:pecl localbase
IGNORE_WITH_PHP=	85

.include <bsd.port.mk>
