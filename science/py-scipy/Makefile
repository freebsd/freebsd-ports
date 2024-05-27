PORTNAME=	scipy
DISTVERSION=	1.12.0
CATEGORIES=	science python
MASTER_SITES=	https://docs.scipy.org/doc/${PORTNAME}-${DISTVERSION}/:doc \
		PYPI:source \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-html-${DISTVERSION}.zip:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scientific tools for Python
WWW=		https://www.scipy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>=0:devel/py-pythran@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pooch>0:devel/py-pooch@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}scikit-umfpack>0:math/py-scikit-umfpack@${PY_FLAVOR}

USES=		compiler:c++14-lang cpe fortran pkgconfig python:3.9-3.11 shebangfix
USE_PYTHON=	autoplist concurrent cython pep517

FFLAGS+=	-std=legacy

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	BLASLIB
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

ATLAS_USES=	blaslapack:atlas
NETLIB_USES=	blaslapack:netlib
OPENBLAS_USES=	blaslapack:openblas

post-patch:
	@${REINPLACE_CMD} -e '23,26s|numpy==|numpy>=|' \
		${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/scipy/ -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${UNZIP_NATIVE_CMD} -d ${STAGEDIR}${DOCSDIR} ${DISTDIR}/scipy-html-${DISTVERSION}.zip
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

#do-test:
#	@cd ${WRKSRC} && ${TOUCH} .coveragerc && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
