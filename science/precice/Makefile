PORTNAME=	precice
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	science # physics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	236e5fb9ad611186515142c2d7538b5c78c6f266.patch:-p1 \
		1d8643401b0a7bfd061d2ee47d6bd9e4cfaf2cca.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coupling library for partitioned multi-physics simulations

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpicxx.so:net/mpich

USES=		cmake:noninja,testing compiler:c++14-lang eigen:3 gnome pkgconfig # fails with ninja: phony target 'binprecice' names itself as an input; ignoring
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_OFF=	BUILD_TESTING PRECICE_ENABLE_FORTRAN PRECICE_PythonActions

OPTIONS_DEFINE=	MPI PETSC EXAMPLES

MPI_CMAKE_BOOL=		PRECICE_MPICommunication
MPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
MPI_RUN_DEPENDS=	openmpi>0:net/openmpi
MPI_BROKEN=		all tests crash with MPI, see https://github.com/precice/precice/issues/1331

PETSC_DESC=		Use PETSc linear algebra library
PETSC_CMAKE_BOOL=	PRECICE_PETScMapping
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_IMPLIES=		MPI

PORTEXAMPLES=		*

# 3 tests are known to fail, see https://github.com/precice/precice/issues/1331

post-install: # remove files which aren't docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
