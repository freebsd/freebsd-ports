PORTNAME=	snmpclitools
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Command-line SNMP utilities in Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysnmp>=4.4.4:net-mgmt/py-pysnmp@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	concurrent distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
