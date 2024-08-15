PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)
WWW=		https://spglib.readthedocs.io/en/stable/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		${PYNUMPY} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail to run, see https://github.com/spglib/spglib/issues/192
USE_GITHUB=	yes

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

TEST_WRKSRC=	${WRKSRC}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch:
	##@cd ${WRKSRC} && ${RLN} ../test .
	#@cd ${WRKSRC} && ${CP} -r ../test .
	# workaround for https://github.com/spglib/spglib/issues/429
	@${REINPLACE_CMD} -i '' -e 's|^from ._version import|#&|' ${WRKSRC}/python/spglib/__init__.py

.include <bsd.port.mk>
