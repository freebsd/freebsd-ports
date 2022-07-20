PORTNAME=	scipy
DISTVERSION=	1.8.1
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
		${PYTHON_PKGNAMEPREFIX}pythran>=0:devel/py-pythran@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libopenblas.so:math/openblas
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang cpe fortran python:3.8-3.10 shebangfix
USE_PYTHON=	autoplist concurrent cython distutils

FFLAGS+=	-std=legacy
LDFLAGS+=	-shared
PYDISTUTILS_BUILDARGS=	--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95

PORTDOCS=	scipy-ref-${PORTVERSION}.pdf

OPTIONS_DEFINE=	DOCS

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/scipy/ -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
