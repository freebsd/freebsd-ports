PORTNAME=	hoomd-blue
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.1
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular dynamics and Monte Carlo soft matter simulation
WWW=		https://glotzerlab.engin.umich.edu/hoomd-blue/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11

USES=		cmake:testing compiler:c++17-lang eigen:3 localbase:ldflags python shebangfix # see https://github.com/glotzerlab/hoomd-blue/issues/1204

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

GH_TUPLE=	glotzerlab:upp11:0c1fb8d:glotzerlab_upp11/hoomd/extern/upp11 \
		glotzerlab:nano-signal-slot:34223a4:glotzerlab_nano_signal_slot/hoomd/extern/nano-signal-slot \
		glotzerlab:quickhull:1ffbc6f:glotzerlab_quickhull/hoomd/extern/quickhull \
		glotzerlab:random123:a2c4f04:glotzerlab_random123/hoomd/extern/random123 \
		glotzerlab:HIP:d211f99:glotzerlab_HIP/hoomd/extern/HIP \
		glotzerlab:hipCUB:c70e193:glotzerlab_hipCUB/hoomd/extern/hipCUB \
		mphowardlab:neighbor:ba0f068:mphowardlab_neighbor/hoomd/extern/neighbor \
		mphowardlab:hipper:b6da049:mphowardlab_hipper/hoomd/extern/hipper

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

# the test mpi-test_communication requires excessive resources, see https://github.com/glotzerlab/hoomd-blue/issues/1396

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/hoomd/ParticleData.cc
.endif

.include <bsd.port.post.mk>
