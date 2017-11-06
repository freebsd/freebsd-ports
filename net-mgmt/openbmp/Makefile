# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbmp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	net-mgmt

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	OpenBMP Server Collector

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librdkafka.so:net/librdkafka \
				libsasl2.so:security/cyrus-sasl2 \
				libyaml-cpp.so:devel/yaml-cpp

USES=		cmake:outsource ssl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenBMP

.include <bsd.port.mk>
