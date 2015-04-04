# Created by: ijliao
# $FreeBSD$

PORTNAME=	scipy
PORTVERSION=	0.15.1
CATEGORIES=	science python
MASTER_SITES=	http://docs.scipy.org/doc/${DISTNAME}/:doc \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-ref-${PORTVERSION}.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scientific tools for Python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran python
USE_PYTHON=	distutils autoplist concurrent

PYDISTUTILS_CONFIGUREARGS+=	--fcompiler=gnu95
PYDISTUTILS_BUILDARGS+=	--fcompiler=gnu95

LDFLAGS+=	-shared

OPTIONS_DEFINE=	ATLAS DOCS SUITESPARSE
OPTIONS_DEFAULT=SUITESPARSE
ATLAS_DESC=	Use optimized blas library
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse

ATLAS_USES=	blaslapack:atlas
ATLAS_USES_OFF=	blaslapack:netlib
SUITESPARSE_LIB_DEPENDS=	libumfpack.so:${PORTSDIR}/math/suitesparse
SUITESPARSE_BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

PORTDOCS=	scipy-ref-${PORTVERSION}.pdf

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MATLAS}
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for scipy to function properly
.endif
.endif

post-extract:
	@${CP} ${DISTDIR}/scipy-ref-${PORTVERSION}.pdf ${WRKDIR}

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s@malloc\.h@stdlib.h@"

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/scipy-ref-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
