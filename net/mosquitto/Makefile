# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	mosquitto
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Open-Source MQTT Broker

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcares.so:${PORTSDIR}/dns/c-ares
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

OPTIONS_DEFAULT=PYTHON
OPTIONS_DEFINE=	PYTHON

PYTHON_DESC=	Build python driver

USES=		cmake python:2
NOCONFIGURE=	yes
USE_RC_SUBR=	mosquitto
USE_LDCONFIG=	yes

USERS=		nobody

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB=	PYTHON_VER=${PYTHON_VER} NOPYTHON="" PORTVERSION=${PORTVERSION}
.else
PLIST_SUB=	NOPYTHON="@comment " PORTVERSION=${PORTVERSION}
.endif

post-patch:
# do not run ldconfig in stage dir
	${REINPLACE_CMD} -e '/ldconfig/d' ${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/lib/CMakeLists.txt ${WRKSRC}/lib/cpp/CMakeLists.txt

post-stage:
.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/lib/python && \
	${PYTHON_CMD} ${WRKSRC}/lib/python/setup.py build install --prefix=${PREFIX} --root=${STAGEDIR})
.endif
# Adjust configuration files
	${MV} ${STAGEDIR}${ETCDIR}/mosquitto.conf ${STAGEDIR}${ETCDIR}/mosquitto.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/pwfile.example ${STAGEDIR}${ETCDIR}/pwfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/pskfile.example ${STAGEDIR}${ETCDIR}/pskfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/aclfile.example ${STAGEDIR}${ETCDIR}/aclfile.sample

.include <bsd.port.mk>
