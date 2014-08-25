# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	1.4.0
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	PHP extension for AMQP API

LIB_DEPENDS=	librabbitmq.so:${PORTSDIR}/net/rabbitmq-c-devel

PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
