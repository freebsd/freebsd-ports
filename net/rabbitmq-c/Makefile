# Created by: Geoff Garside
# $FreeBSD$

PORTNAME=	rabbitmq-c
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	freebsd@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson

CONFLICTS=	rabbitmq-c-devel-[0-9]*

USES=		cmake pathfix python tar:bzip2
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	alanxz

OPTIONS_DEFINE=	POPT
OPTIONS_SUB=	yes
POPT_DESC=	Popt support in tools
POPT_LIB_DEPENDS=	libpopt.so:devel/popt
POPT_CFLAGS=	-I${LOCALBASE}/include
POPT_LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
