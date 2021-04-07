PORTNAME=	coinmumps
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.6.2
CATEGORIES=	math
MASTER_SITES=	http://coin-or-tools.github.io/ThirdParty-Mumps/:mumps
PKGNAMEPREFIX=	coin-or-
DISTFILES=	MUMPS_${MUMPS_VERSION}.tar.gz:mumps

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver (MUMPS)

LICENSE=	PD
LICENSE_FILE=	${WRKDIR}/MUMPS_${MUMPS_VERSION}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas

USES=		fortran gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or-tools
GH_PROJECT=	ThirdParty-Mumps

INSTALL_TARGET=	install-strip

MUMPS_VERSION=	4.10.0

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-extract:
	@${RLN} ${WRKDIR}/MUMPS_${MUMPS_VERSION} ${WRKSRC}/MUMPS

post-patch: # from get.Mumps
	@cd ${WRKSRC} && \
		${PATCH} -p0 < mumps.patch && \
		${PATCH} -p0 < mumps_mpi.patch && \
		${MV} MUMPS/libseq/mpi.h MUMPS/libseq/mumps_mpi.h

.include <bsd.port.post.mk>
