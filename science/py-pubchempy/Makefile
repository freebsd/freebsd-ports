PORTNAME=	pubchempy
DISTVERSION=	1.0.5
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for the PubChem PUG REST API
WWW=		https://github.com/mcs07/PubChemPy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# tests as of 1.0.5: not enabled because every upstream test queries the live
# PubChem REST API, which is unavailable in the clean poudriere test environment.

.include <bsd.port.mk>
