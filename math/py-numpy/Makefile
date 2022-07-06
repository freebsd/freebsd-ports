# Created by: Tony Maher

PORTNAME=	numpy
PORTVERSION=	1.23.0
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP \
		https://numpy.org/doc/${PORTVERSION:R}/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-ref.pdf:doc \
		${PORTNAME}-user.pdf:doc
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION:R}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The New Numeric Extension to Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.2.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.24.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR}
USES=		compiler:c11 cpe fortran python:3.8-3.10
USE_PYTHON=	allflavors autoplist concurrent cython distutils

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so | ${SED} -e s/libgfortran.so//
LDFLAGS+=	-s
PYDISTUTILS_BUILDARGS=		--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SUITESPARSE
OPTIONS_SINGLE=		BLASLIB
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS SUITESPARSE
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse

ATLAS_USES=		blaslapack:atlas
ATLAS_VARS=		BLASLIBS="ptf77blas, ptcblas" BLASNAME=atlas LAPACKLIBS=alapack LIBRARIES=atlas_libs
NETLIB_USES=		blaslapack:netlib
NETLIB_VARS=		BLASLIBS="blas, cblas" BLASNAME=atlas LAPACKLIBS=lapack LIBRARIES=atlas_libs
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_VARS=		BLASLIBS="openblas, gfortran" BLASNAME=openblas LAPACKLIBS="openblas, gfortran" LIBRARIES=libraries
SUITESPARSE_LIB_DEPENDS=libumfpack.so:math/suitesparse-umfpack

post-extract:
	@${TOUCH} ${WRKSRC}/numpy/f2py/tests/src/temp
	@${TOUCH} ${WRKSRC}/numpy/random/_examples/temp
	@${TOUCH} ${WRKSRC}/numpy/core/tests/examples/temp

pre-configure-SUITESPARSE-off:
	@${REINPLACE_CMD} -e 's|:%%LOCALBASE%%/include/suitesparse||' ${WRKSRC}/site.cfg

pre-configure:
	@${REINPLACE_CMD} -e 's|%%FC%%|${FC}|' ${WRKSRC}/numpy/distutils/fcompiler/gnu.py
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%BLASLIBS%%|${BLASLIBS}|; s|%%BLASNAME%%|${BLASNAME}|' \
		-e 's|%%LAPACKLIBS%%|${LAPACKLIBS}|; s|%%LIBRARIES%%|${LIBRARIES}|' \
			${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s|%%GCCLIBDIR%%|$$(${GCCLIBDIR_CMDS})|" ${WRKSRC}/site.cfg ${WRKSRC}/numpy/distutils/system_info.py

do-configure:

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-ref.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-user.pdf ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
