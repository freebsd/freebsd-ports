# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	mosquitto
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Open-Source MQTT Broker

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcares.so:dns/c-ares
BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		cmake python:2
NOCONFIGURE=	yes
USE_RC_SUBR=	mosquitto
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

USERS=		nobody

post-patch:
# do not run ldconfig in stage dir
	${REINPLACE_CMD} -e '/ldconfig/d' ${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/lib/CMakeLists.txt ${WRKSRC}/lib/cpp/CMakeLists.txt

post-stage:
# Adjust configuration files
	${MV} ${STAGEDIR}${ETCDIR}/mosquitto.conf ${STAGEDIR}${ETCDIR}/mosquitto.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/pwfile.example ${STAGEDIR}${ETCDIR}/pwfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/pskfile.example ${STAGEDIR}${ETCDIR}/pskfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/aclfile.example ${STAGEDIR}${ETCDIR}/aclfile.sample

.include <bsd.port.mk>
