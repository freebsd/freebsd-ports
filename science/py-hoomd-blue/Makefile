PORTNAME=	hoomd-blue
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0-beta.14
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular dynamics and Monte Carlo soft matter simulation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11

USES=		cmake:testing compiler:c++17-lang eigen:3 localbase:ldflags python shebangfix # see https://github.com/glotzerlab/hoomd-blue/issues/1204

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

GH_TUPLE=	glotzerlab:upp11:0c1fb8dfb4bcdc1c5c4eff9165539b15e70c4360:glotzerlab_upp11/hoomd/extern/upp11 \
		glotzerlab:nano-signal-slot:34223a4a7e97f8e114ef007e5360cf7a71265da3:glotzerlab_nano_signal_slot/hoomd/extern/nano-signal-slot \
		glotzerlab:cub:c3cceac115c072fb63df1836ff46d8c60d9eb304:glotzerlab_cub/hoomd/extern/cub \
		glotzerlab:quickhull:a706b5ba0d863b241668038be9eef67afbfaabac:glotzerlab_quickhull/hoomd/extern/quickhull \
		glotzerlab:random123:7f2371b8c597a486cd33fb421a196d78efe08043:glotzerlab_random123/hoomd/extern/random123 \
		glotzerlab:HIP:849fb35f674c12f7c534153e2656b27997641866:glotzerlab_HIP/hoomd/extern/HIP \
		glotzerlab:hipCUB:c70e19332a8402049b3359b409e50220a759c42d:glotzerlab_hipCUB/hoomd/extern/hipCUB \
		mphowardlab:neighbor:ba0f06869b766066a7068852fa3b8c5fa746f71f:mphowardlab_neighbor/hoomd/extern/neighbor \
		mphowardlab:hipper:b6da049a516ada03e4e1b66ca6b4c2c7c9668595:mphowardlab_hipper/hoomd/extern/hipper \
		glotzerlab:hoomd-examples:78174286427a2ec1c23e84015f7b4ba4f5f86d20:glotzerlab_hoomd_examples/sphinx-doc/tutorial

SHEBANG_GLOB=	*.sh

CMAKE_OFF=	BUILD_TESTING

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		MPI TBB
OPTIONS_DEFAULT=	MPI TBB
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_BUILD_DEPENDS=	cereal>0:devel/cereal
MPI_LIB_DEPENDS=	libmpi.so:net/mpich

TBB_DESC=		Enable support for Threading Building Blocks (TBB)
TBB_CMAKE_BOOL=		ENABLE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

.include <bsd.port.mk>
