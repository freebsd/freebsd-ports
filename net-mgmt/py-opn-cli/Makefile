# Created by: Frank Wall <fw@moov.de>

PORTNAME=	opn-cli
PORTVERSION=	0.3.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fw@moov.de
COMMENT=	OPNsense CLI written in Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+

USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
