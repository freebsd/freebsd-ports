PORTNAME=	hared
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Small Python server for inserting notications into MQTT

LICENSE=	MIT

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

ETCDIR=		${PREFIX}/etc

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR}

CONFLICTS_INSTALL=	hared

pre-install:
	${INSTALL_DATA} ${FILESDIR}/hared.conf ${STAGEDIR}${ETCDIR}/hared.ini.sample

.include <bsd.port.mk>
