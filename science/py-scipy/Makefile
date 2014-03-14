# Created by: ijliao
# $FreeBSD$

PORTNAME=	scipy
PORTVERSION=	0.13.3
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	http://docs.scipy.org/doc/${DISTNAME}/:doc \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-ref.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific tools for Python

LICENSE=	BSD

BUILD_DEPENDS+=	${PYNUMPY} \
		${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${PYNUMPY}	\
		nosetests:${PORTSDIR}/devel/py-nose

LATEST_LINK=	py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-numpy/options

USES=		fortran
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

OPTIONS_DEFINE=	ATLAS DOCS SUITESPARSE
OPTIONS_DEFAULT=SUITESPARSE
ATLAS_DESC=	Use optimized blas library
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse

NO_STAGE=	yes
post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s@malloc\.h@stdlib.h@"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for scipy to function properly
.endif
.else
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack \
		libblas.so:${PORTSDIR}/math/blas
.endif

.if ${PORT_OPTIONS:MSUITESPARSE}
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS+=	libumfpack.so:${PORTSDIR}/math/suitesparse
.endif

PYDISTUTILS_CONFIGUREARGS+=	--fcompiler=gnu95
PYDISTUTILS_BUILDARGS+=	--fcompiler=gnu95

post-extract:
	@${CP} ${DISTDIR}/scipy-ref.pdf ${WRKDIR}

post-install:
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/scipy ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/scipy -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/scipy-ref.pdf ${DOCSDIR}
	@${ECHO_CMD} ${DOCSDIR}/scipy-ref.pdf | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} ${DOCSDIR} | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
