PORTNAME=	hared
PORTVERSION=	1.3
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Small Python server for inserting notications into MQTT
WWW=		https://github.com/jpmens/hared-hare

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

ETCDIR=		${PREFIX}/etc

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR}

CONFLICTS_INSTALL=	hared

pre-install:
	${INSTALL_DATA} ${FILESDIR}/hared.conf ${STAGEDIR}${ETCDIR}/hared.ini.sample

.include <bsd.port.mk>
