PORTNAME=	hjson
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	User interface for JSON written in Python
WWW=		https://github.com/hjson/hjson-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
# Use GitHub instead of PYPI to get the test files.
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-py
GH_TAGNAME=	22fd1c9f6af5790a396f38c3f6a97099b5fdc32a
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
