PORTNAME=	periodictable
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tarball available
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extensible periodic table of the elements pre-populated with data
WWW=		https://periodictable.readthedocs.io/en/latest/ \
		https://github.com/python-periodictable/periodictable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail to run, see https://github.com/python-periodictable/periodictable/issues/106

USE_GITHUB=	yes
GH_ACCOUNT=	python-periodictable

NO_ARCH=	yes

.include <bsd.port.mk>
