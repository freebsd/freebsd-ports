PORTNAME=	python-ly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.9
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python package to manipulate LilyPond files
WWW=		https://github.com/frescobaldi/python-ly

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi

USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
