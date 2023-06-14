PORTNAME=	python-ly
PORTVERSION=	0.9.8
DISTVERSIONPREFIX=	v
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python package to manipulate LilyPond files
WWW=		https://github.com/frescobaldi/python-ly

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi

USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
