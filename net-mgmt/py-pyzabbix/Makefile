# Created by: Fotis Zabaras <fotis@zabaras.eu>
# $FreeBSD$

PORTNAME=	pyzabbix
PORTVERSION=	0.7.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fotis@zabaras.eu
COMMENT=	Zabbix API Python Library

LICENSE=	LGPL21

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
