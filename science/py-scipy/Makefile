# Created by: ijliao

PORTNAME=	scipy
DISTVERSION=	1.7.1
CATEGORIES=	science python
MASTER_SITES=	https://docs.scipy.org/doc/scipy-${PORTVERSION}/:doc \
		CHEESESHOP:source \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-ref-${PORTVERSION}.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scientific tools for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>=0:devel/py-pythran
LIB_DEPENDS=	libblas.so:math/blas \
		libopenblas.so:math/openblas
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang cpe fortran python:3.7+ shebangfix
USE_PYTHON=	autoplist concurrent cython distutils

FFLAGS+=	-std=legacy
LDFLAGS+=	-shared
PYDISTUTILS_BUILDARGS=	--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95

PORTDOCS=	scipy-ref-${PORTVERSION}.pdf

SHEBANG_FILES=	scipy/sparse/linalg/isolve/tests/test_gcrotmk.py

OPTIONS_DEFINE=	DOCS

post-patch:
# This line help fix the plist error because autoplist list it as a file but it is a directory
	@${TOUCH} ${WRKSRC}/scipy/stats/tests/data/tmp

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/scipy/ -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
