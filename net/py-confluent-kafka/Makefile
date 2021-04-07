PORTNAME=	confluent-kafka
DISTVERSION=	1.2.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Confluent Apache Kafka Python client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	librdkafka.so:net/librdkafka

USES=		localbase python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/confluent_kafka/cimpl*.so

.include <bsd.port.mk>
