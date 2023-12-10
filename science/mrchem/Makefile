PORTNAME=	mrchem
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MultiResolution Chemistry
WWW=		https://github.com/MRChemSoft/mrchem

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libmrcpp.so:science/mrcpp \
		libxcfun.so:science/xcfun

USES=		cmake:testing compiler:c++14-lang eigen:3 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	MRChemSoft

SHEBANG_FILES=	python/mrchem.in tests/*/test

OPTIONS_DEFINE=		ARCH_FLAGS PYTHON # the Python module also exists in the separate port science/py-mrchem, so it should be off by default here
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH
OPTIONS_SUB=		yes

ARCH_FLAGS_DESC=	Enable architecture-specific compiler flags
ARCH_FLAGS_CMAKE_BOOL=	ENABLE_ARCH_FLAGS

NOMPI_DESC=		Build without parallel processing support

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON
OPENMPI_BROKEN=		fails to compile with OpenMPI, see https://github.com/MRChemSoft/mrchem/issues/438

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_CMAKE_ON=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
			-DPYMOD_INSTALL_LIBDIR=${PYTHON_SITELIBDIR:S;${PREFIX}/lib/;;}

post-install-PYTHON-on:
	@${RMDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mrchem/input_parser/docs

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MPYTHON}
pre-test:
	@${ECHO} "tests require the port to be built with PYTHON=ON" && false

.endif

.include <bsd.port.mk>
