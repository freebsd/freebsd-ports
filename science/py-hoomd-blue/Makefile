PORTNAME=	hoomd-blue
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.0
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular dynamics and Monte Carlo soft matter simulation
WWW=		https://glotzerlab.engin.umich.edu/hoomd-blue/ \
		https://github.com/glotzerlab/hoomd-blue

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11

USES=		cmake:testing compiler:c++17-lang eigen:3 localbase:ldflags python shebangfix # see https://github.com/glotzerlab/hoomd-blue/issues/1204

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

GH_TUPLE=	glotzerlab:upp11:0c1fb8dfb4bcdc1c5c4eff9165539b15e70c4360:glotzerlab_upp11/hoomd/extern/upp11 \
		glotzerlab:nano-signal-slot:8d13689:glotzerlab_nano_signal_slot/hoomd/extern/nano-signal-slot \
		glotzerlab:quickhull:1ffbc6f884ea1da89e104a5996cf8a726db673d5:glotzerlab_quickhull/hoomd/extern/quickhull \
		glotzerlab:HIP:db753e4:glotzerlab_HIP/hoomd/extern/HIP \
		glotzerlab:hipCUB:64d8adf:glotzerlab_hipCUB/hoomd/extern/hipCUB \
		mphowardlab:neighbor:ba0f06869b766066a7068852fa3b8c5fa746f71f:mphowardlab_neighbor/hoomd/extern/neighbor \
		mphowardlab:hipper:076059b:mphowardlab_hipper/hoomd/extern/hipper \
		glotzerlab:hoomd-examples:94a5b52d159bc7c07e2650e31b429cef55384542:glotzerlab_hoomd_examples/sphinx-doc/tutorial \
		glotzerlab:OpenRAND:92dc12a:glotzerlab_OpenRAND/hoomd/extern/OpenRAND \
		mphowardlab:hipper:b6da049a516ada03e4e1b66ca6b4c2c7c9668595:mphowardlab_hipper/hoomd/extern/hipper

SHEBANG_GLOB=	*.sh

CMAKE_OFF=	BUILD_TESTING

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		TBB
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH TBB
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support
NOMPI_CMAKE_ON=		-DENABLE_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON
MPICH_BUILD_DEPENDS=	cereal>0:devel/cereal

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON
OPENMPI_BUILD_DEPENDS=	cereal>0:devel/cereal
OPENMPI_BROKEN=		see https://github.com/glotzerlab/hoomd-blue/issues/1397

TBB_DESC=		Enable support for Threading Building Blocks (TBB)
TBB_CMAKE_BOOL=		ENABLE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

# tests as of 6.0.0: 97% tests passed, 2 tests failed out of 67
# The following tests FAILED:
#          18 - mpi-test_load_balancer (Failed)
#          35 - mpi-test_communication (Failed)

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/hoomd/ParticleData.cc
.endif

.include <bsd.port.post.mk>
