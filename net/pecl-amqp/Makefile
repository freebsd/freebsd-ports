PORTNAME=	amqp
PORTVERSION=	1.11.0
CATEGORIES=	net pear

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PHP extension for AMQP API
WWW=		https://pecl.php.net/package/amqp

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c-devel

USES=		php:pecl localbase
IGNORE_WITH_PHP=	82

.include <bsd.port.mk>
