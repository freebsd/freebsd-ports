PORTNAME=	confluent-kafka
DISTVERSION=	1.2.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Confluent Apache Kafka Python client
WWW=		https://github.com/confluentinc/confluent-kafka-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	librdkafka.so:net/librdkafka

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/confluent_kafka/cimpl*.so

.include <bsd.port.mk>
