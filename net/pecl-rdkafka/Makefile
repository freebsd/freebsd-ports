PORTNAME=	rdkafka
DISTVERSION=	6.0.5
CATEGORIES=	net pear

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Kafka client for PHP
WWW=		https://github.com/php-rdkafka/php-rdkafka/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librdkafka.so:net/librdkafka

USES=		php:pecl

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 86
post-patch:
	@${REINPLACE_CMD} -e 's|XtOffsetOf|offsetof|' \
			  -e 's|zval_dtor|zval_ptr_dtor_nogc|' \
		${WRKSRC}/*.c ${WRKSRC}/*.h
.endif

.include <bsd.port.post.mk>
