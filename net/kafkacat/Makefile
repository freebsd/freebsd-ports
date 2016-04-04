# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	kafkacat
PORTVERSION=	1.2.0
CATEGORIES=	net
DISTNAME=	${GH_ACCOUNT}-${PORTNAME}-${PORTVERSION}-${GH_TAGNAME}

MAINTAINER=	xnasx@yandex.ru
COMMENT=	Generic command line non-JVM Apache Kafka producer and consumer

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		pkg-config:devel/pkgconf
LIB_DEPENDS=	librdkafka.so:net/librdkafka

USE_GITHUB=	yes
GH_ACCOUNT=	edenhill
GH_TAGNAME=	e2806ae

PLIST_FILES=	bin/kafkacat

USES=	perl5 gmake
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
