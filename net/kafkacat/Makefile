# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	kafkacat
DISTVERSION=	1.6.0
CATEGORIES=	net

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Generic command line non-JVM Apache Kafka producer and consumer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	librdkafka.so:net/librdkafka \
		libyajl.so:devel/yajl

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	edenhill

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/kafkacat

OPTIONS_DEFINE=	JSON AVRO

AVRO_DESC=	Avro/Schema-Registry support (requires libserdes) [BROKEN]
JSON_DESC=	JSON support (requires libyajl2)

# avro broken due to bug: https://github.com/apache/avro/pull/1018/commits
AVRO_BROKEN=		avro support is currently broken
AVRO_LIB_DEPENDS=	libserdes.so:devel/libserdes
AVRO_CONFIGURE_ENABLE=	avro
JSON_LIB_DEPENDS=	libyajl.so:devel/yajl
JSON_CONFIGURE_ENABLE=	json

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kafkacat

.include <bsd.port.mk>
