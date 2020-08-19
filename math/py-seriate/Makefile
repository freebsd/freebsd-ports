# $FreeBSD$

PORTNAME=	seriate
DISTVERSION=	1.1.2
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimal ordering of elements in a set given their distance matrix

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}or-tools>0:math/py-or-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	src-d
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
