# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	mosquitto
PORTVERSION=	1.3.2
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

USES=		cmake
USE_PYTHON=	2
NOCONFIGURE=	yes
USE_RC_SUBR=	mosquitto
MANCOMPRESSED=	no
NO_MANCOMPRESS=	yes
USE_LDCONFIG=	yes

USERS=		nobody

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB=	PYTHON_VER=${PYTHON_VER} NOPYTHON=""
.else
PLIST_SUB=	NOPYTHON="@comment "
.endif

post-patch:
	${MV} ${WRKSRC}/mosquitto.conf ${WRKSRC}/mosquitto.conf.example

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	cd ${WRKSRC}/lib/python ; \
	${PYTHON_CMD} ${WRKSRC}/lib/python/setup.py build ; \
	${PYTHON_CMD} ${WRKSRC}/lib/python/setup.py install --prefix=${PREFIX} --root=${STAGEDIR}
.endif
	# Compress Man Pages
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man8/mosquitto.8
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man7/mqtt.7
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man7/mosquitto-tls.7
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man5/mosquitto.conf.5
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man3/libmosquitto.3
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_sub.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_pub.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_passwd.1
	# Adjust configuration files
	${MV} ${STAGEDIR}${PREFIX}/etc/mosquitto/mosquitto.conf.example ${STAGEDIR}${PREFIX}/etc/mosquitto/mosquitto.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/mosquitto/pwfile.example ${STAGEDIR}${PREFIX}/etc/mosquitto/pwfile.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/mosquitto/pskfile.example ${STAGEDIR}${PREFIX}/etc/mosquitto/pskfile.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/mosquitto/aclfile.example ${STAGEDIR}${PREFIX}/etc/mosquitto/aclfile.sample

.include <bsd.port.mk>
