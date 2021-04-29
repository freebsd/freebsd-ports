PORTNAME=	siesta
DISTVERSION=	4.1.5
CATEGORIES=	science
MASTER_SITES=	https://gitlab.com/siesta-project/${PORTNAME}/-/releases/v${DISTVERSION}/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program to perform efficient electronic structure calculations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake localbase:ldflags

ALL_TARGET=	default

WRKSRC_SUBDIR=	Obj

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	gfortran=gfortran${GCC_DEFAULT} gcc=gcc${GCC_DEFAULT}

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (COMPLEX(8)/REAL(8)).
FFLAGS+=	-fallow-argument-mismatch
MAKE_ARGS=	FFLAGS="${FFLAGS} -O2 -fPIC -ftree-vectorize"
.endif

pre-configure:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SH} ../Src/obj_setup.sh && \
		${LN} -s gfortran.make arch.make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
