PORTNAME=	packet-python
DISTVERSION=	1.37.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Python client for Packet.net API

LICENSE=	LGPL3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.18.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
