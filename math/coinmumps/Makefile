# $FreeBSD$

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

post-extract:
	@${RLN} ${WRKDIR}/MUMPS_${MUMPS_VERSION} ${WRKSRC}/MUMPS

post-patch: # from get.Mumps
	@cd ${WRKSRC} && \
		${PATCH} -p0 < mumps.patch && \
		${PATCH} -p0 < mumps_mpi.patch && \
		${MV} MUMPS/libseq/mpi.h MUMPS/libseq/mumps_mpi.h

.include <bsd.port.mk>
