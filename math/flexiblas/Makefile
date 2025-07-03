PORTNAME=	flexiblas
PORTVERSION=	3.4.5
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math
#MASTER_SITES=	https://csc.mpi-magdeburg.mpg.de/mpcsc/software/flexiblas/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	BLAS and LAPACK wrapper library with runtime exchangable backends
WWW=		https://www.mpi-magdeburg.mpg.de/projects/flexiblas

LICENSE=	LGPL3

LIB_DEPENDS=	libblas.so:math/blas	\
		libblis.so:math/blis	\
		liblapack.so:math/lapack

USES=		cmake:testing fortran python tar:xz
CMAKE_ARGS=	-DLTO:BOOL=OFF

USE_GITLAB=	yes
GL_SITE=	https://gitlab.mpi-magdeburg.mpg.de/
GL_ACCOUNT=	software
GL_PROJECT=	${PORTNAME}-release

CONFIGURE_ENV=	PYTHON_EXECUTABLE=${PYTHON_CMD}
USE_LDCONFIG=	yes

PLIST_SUB=	VE=${PORTVERSION:R}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DFIND_DEBUG:BOOL=ON
.endif

OPTIONS_DEFINE=		DOCS EXAMPLES

EXAMPLES_CMAKE_ON=	-DEXAMPLES:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DEXAMPLES:BOOL=OFF

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so)
LIB_DEPENDS+=	libatlas.so:math/atlas
PLIST_SUB+=	OPENBLAS="@comment " ATLAS=""
.else
LIB_DEPENDS+=	libcblas.so:math/cblas	\
		libopenblas.so:math/openblas
PLIST_SUB+=	OPENBLAS="" ATLAS="@comment "
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/flexiblasrc	\
		${STAGEDIR}${PREFIX}/etc/flexiblasrc.sample

.include <bsd.port.post.mk>
