# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	numpy
PORTVERSION=	1.13.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	http://docs.scipy.org/doc/${PORTNAME}-${PORTVERSION:R}.0/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-ref-${PORTVERSION:R}.0.pdf:doc \
		${PORTNAME}-user-${PORTVERSION:R}.0.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The New Numeric Extension to Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PYDISTUTILS_BUILDARGS=		--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95
USES=		fortran python
USE_GITHUB=	yes
USE_PYTHON=	concurrent distutils py3kplist cython allflavors
LDFLAGS+=	-shared

OPTIONS_DEFINE=		DOCS SUITESPARSE TESTS
OPTIONS_SINGLE=		BLASLIB
OPTIONS_DEFAULT=	NETLIB SUITESPARSE
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse
TESTS_DESC=		Install test suite requirements

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
PORTDOCS=	*

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so | ${SED} -e s/libgfortran.so//

ATLAS_USES=		blaslapack:atlas
NETLIB_USES=		blaslapack:netlib
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
OPENBLAS_USES=		blaslapack:openblas
SUITESPARSE_LIB_DEPENDS=libumfpack.so:math/suitesparse
TESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR}

.include <bsd.port.pre.mk>

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
	${INSTALL_MAN} ${WRKSRC}/doc/f2py/f2py.1 ${STAGEDIR}${MANPREFIX}/man/man1/f2py.1
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-ref-${PORTVERSION:C/\.[0-9]+$/.0/}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-user-${PORTVERSION:C/\.[0-9]+$/.0/}.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
