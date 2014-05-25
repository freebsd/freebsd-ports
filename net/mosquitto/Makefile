# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	mosquitto
PORTVERSION=	1.3.1
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Open-Source MQTT Broker

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcares.so:${PORTSDIR}/dns/c-ares
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USES=		cmake
USE_PYTHON=	2
NOCONFIGURE=	yes
USE_RC_SUBR=	mosquitto
MANCOMPRESSED=	no
NO_MANCOMPRESS=	yes
USE_LDCONFIG=	yes

USERS=		nobody

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

post-patch:
	${MV} ${WRKSRC}/mosquitto.conf ${WRKSRC}/mosquitto.conf.example

post-install:
	cd ${WRKSRC}/lib/python ; \
	${PYTHON_CMD} ${WRKSRC}/lib/python/setup.py build ; \
	${PYTHON_CMD} ${WRKSRC}/lib/python/setup.py install --prefix=${PREFIX} --root=${STAGEDIR}

	# Compress Man Pages
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man8/mosquitto.8
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man7/mqtt.7
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man7/mosquitto-tls.7
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man5/mosquitto.conf.5
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man3/libmosquitto.3
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_sub.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_pub.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/mosquitto_passwd.1

.include <bsd.port.mk>
