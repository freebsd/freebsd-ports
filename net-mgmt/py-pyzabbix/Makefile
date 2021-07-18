# Created by: Fotis Zabaras <fotis@zabaras.eu>

PORTNAME=	pyzabbix
PORTVERSION=	1.0.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Zabbix API Python Library

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.8.5:devel/py-semantic-version@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
