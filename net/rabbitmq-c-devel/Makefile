# Created by: Geoff Garside
# $FreeBSD$

PORTNAME=	rabbitmq-c
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-devel

MAINTAINER=	rabbitmq@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

LICENSE=	GPLv2 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson

CONFLICTS=	rabbitmq-c-[0-9]*

USES=		cmake python tar:bzip2
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	alanxz
GH_COMMIT=	e554ca7
GH_TAGNAME=	v${PORTVERSION}

OPTIONS_DEFINE=	POPT
POPT_DESC=	Popt support in tools

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOPT}
LIB_DEPENDS+=	libpopt.so:${PORTSDIR}/devel/popt
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	POPT=""
.else
PLIST_SUB+=	POPT="@comment "
.endif

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/librabbitmq.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/librabbitmq.pc
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
