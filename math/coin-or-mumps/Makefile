PORTNAME=	mumps
DISTVERSIONPREFIX=	releases/
DISTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://coin-or-tools.github.io/ThirdParty-Mumps/:mumps
PKGNAMEPREFIX=	coin-or-
DISTFILES=	MUMPS_${MUMPS_VERSION}.tar.gz:mumps

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	COIN-OR autotools harness to build Mumps
WWW=		https://github.com/coin-or-tools/ThirdParty-Mumps

LICENSE=	EPL

LIB_DEPENDS=	libblas.so:math/blas \
		libcoinmetis.so:math/coin-or-metis \
		liblapack.so:math/lapack

USES=		fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or-tools
GH_PROJECT=	ThirdParty-Mumps

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes # otherwise build doesn't find some *.mod files

INSTALL_TARGET=	install-strip

MUMPS_VERSION=	5.5.0 # from the script get.Mumps

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-extract: # link MUMPS into the location in the tree
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/MUMPS_${MUMPS_VERSION} MUMPS

post-patch: # patching from get.Mumps
	@cd ${WRKSRC} && \
		${PATCH} -p0 < mumps_mpi.patch && \
		${MV} MUMPS/libseq/mpi.h MUMPS/libseq/mumps_mpi.h

.include <bsd.port.post.mk>
