PORTNAME=	gemmi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.8
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Macromolecular crystallography library and utilities
WWW=		https://gemmi.readthedocs.io/en/latest/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		pybind11>=2.6:devel/pybind11

USES=		cmake compiler:c++17-lang python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	project-gemmi

CMAKE_ON=	USE_PYTHON

PLIST_FILES=	${PYTHON_SITELIBDIR}/gemmi${PYTHON_EXT_SUFFIX}.so

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKSRC}/tests

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest discover -v tests/

.include <bsd.port.mk>
