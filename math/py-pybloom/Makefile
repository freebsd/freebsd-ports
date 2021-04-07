PORTNAME=	pybloom
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Probabilistic data structure

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitarray>0:devel/py-bitarray@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	joseph-fox
GH_PROJECT=	python-bloomfilter

.include <bsd.port.mk>
