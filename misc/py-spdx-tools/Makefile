PORTNAME=	spdx-tools
DISTVERSION=	0.8.3
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parses, validates and creates SPDX documents
WWW=		https://github.com/spdx/tools-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=0:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beartype>=0:devel/py-beartype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritools>=0:net/py-uritools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}license-expression>=0:textproc/py-license-expression@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=0:devel/py-semantic-version@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} LC_ALL=en_US.UTF-8

NO_ARCH=	yes
PLIST_FILES=	${PYTHON_SITELIBDIR}/spdx_tools/spdx/parser/tagvalue/parser.out
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

pre-build:
	${SETENVI} PYTHONPATH=${WRKSRC}/src:${PYTHON_LIBDIR} ${PYTHON_CMD} ${FILESDIR}/generate-parser.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR} \;
	${INSTALL_DATA} ${WRKSRC}/src/spdx_tools/spdx/parser/tagvalue/parser.out \
		${STAGEDIR}${PYTHON_SITELIBDIR}/spdx_tools/spdx/parser/tagvalue

# This test requires https://github.com/RDFLib/pySHACL, which is not currently
# in the ports tree. Using PYTEST_IGNORED_TESTS doesn't seem to work in this
# case, so just delete it for now so that the other tests pass.
pre-test:
	${RM} ${WRKSRC}/tests/spdx3/validation/json_ld/test_shacl_validation.py

.include <bsd.port.mk>
