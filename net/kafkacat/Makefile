# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	kafkacat
PORTVERSION=	1.3.1
CATEGORIES=	net

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Generic command line non-JVM Apache Kafka producer and consumer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	librdkafka.so:net/librdkafka

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	edenhill

PLIST_FILES=	bin/kafkacat

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kafkacat

.include <bsd.port.mk>
