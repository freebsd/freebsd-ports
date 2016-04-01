# Created by: Geoff Garside
# $FreeBSD$

PORTNAME=	rabbitmq-c
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMESUFFIX=	-devel

MAINTAINER=	freebsd@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

LICENSE=	GPLv2 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson

CONFLICTS=	rabbitmq-c-[0-9]*

USES=		cmake python tar:bzip2
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	alanxz

OPTIONS_DEFINE=	POPT
OPTIONS_SUB=	yes
POPT_DESC=	Popt support in tools
POPT_LIB_DEPENDS=	libpopt.so:devel/popt
POPT_CFLAGS=	-I${LOCALBASE}/include
POPT_LDFLAGS=	-L${LOCALBASE}/lib

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/librabbitmq.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/librabbitmq.pc
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
