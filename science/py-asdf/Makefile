# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asdf
PORTVERSION=	2.3.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python tools to handle ASDF files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.3:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0.10:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.8:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic_version>=2.3.1:devel/py-semantic_version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
