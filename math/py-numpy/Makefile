# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	numpy
PORTVERSION=	1.15.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP \
		https://docs.scipy.org/doc/${PORTNAME}-${PORTVERSION}/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-ref-${PORTVERSION}.pdf:doc \
		${PORTNAME}-user-${PORTVERSION}.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The New Numeric Extension to Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fortran python zip
USE_PYTHON=	allflavors autoplist concurrent cython distutils

PYDISTUTILS_BUILDARGS=		--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95
LDFLAGS+=	-shared

OPTIONS_DEFINE=		DOCS SUITESPARSE
OPTIONS_SINGLE=		BLASLIB
OPTIONS_DEFAULT=	NETLIB SUITESPARSE
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse
TESTS_DESC=		Install test suite requirements

PORTDOCS=	*

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so | ${SED} -e s/libgfortran.so//

ATLAS_USES=		blaslapack:atlas
NETLIB_USES=		blaslapack:netlib
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
OPENBLAS_USES=		blaslapack:openblas
SUITESPARSE_LIB_DEPENDS=libumfpack.so:math/suitesparse
TEST_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

post-extract:
	@${TOUCH} ${WRKSRC}/numpy/f2py/tests/src/temp

post-patch:
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|" ${WRKSRC}/numpy/distutils/fcompiler/gnu.py
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg

pre-configure:
	@${REINPLACE_CMD} -e "s|%%GCCLIBDIR%%|$$(${GCCLIBDIR_CMDS})|" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
			${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s|%%GCCLIBDIR%%|$$(${GCCLIBDIR_CMDS})|" ${WRKSRC}/numpy/distutils/system_info.py

pre-configure-ATLAS-on:
	@${REINPLACE_CMD} -e "s|%%BLASNAME%%|atlas|" \
		-e "s|%%LIBRARIES%%|atlas_libs|" \
		-e "s|%%BLASLIBS%%|%%ATLASLIBS%%|" \
		-e "s|%%LAPACKLIBS%%|alapack|" \
		-e "s|%%ATLASLIBS%%|ptf77blas, ptcblas|" \
			${WRKSRC}/site.cfg

pre-configure-NETLIB-on:
	@${REINPLACE_CMD} -e "s|%%BLASNAME%%|atlas|" \
		-e "s|%%LIBRARIES%%|atlas_libs|" \
		-e "s|%%BLASLIBS%%|blas, cblas|" \
		-e "s|%%LAPACKLIBS%%|lapack|" \
			${WRKSRC}/site.cfg

pre-configure-OPENBLAS-on:
	@${REINPLACE_CMD} -e "s|%%BLASNAME%%|openblas|" \
		-e "s|%%LIBRARIES%%|libraries|" \
		-e "s|%%LAPACKLIBS%%|%%BLASLIBS%%|" \
		-e "s|%%BLASLIBS%%|openblasp, gfortran|" \
			${WRKSRC}/site.cfg

pre-configure-SUITESPARSE-off:
	@${REINPLACE_CMD} -e "s|:%%LOCALBASE%%/include/suitesparse||" ${WRKSRC}/site.cfg

post-install:
#	${INSTALL_MAN} ${WRKSRC}/doc/f2py/f2py.1 ${STAGEDIR}${MANPREFIX}/man/man1/f2py.1
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-ref-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-user-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
