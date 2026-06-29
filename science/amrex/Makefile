PORTNAME=	amrex
DISTVERSION=	26.06
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AMReX: Software Framework for Block Structured AMR
WWW=		https://amrex-codes.github.io/index.html \
		https://github.com/AMReX-Codes/amrex

LICENSE=	APACHE20

USES=		cmake:testing compiler:c++20-lang mpi:openmpi perl5 python shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AMReX-Codes

SHEBANG_GLOB=	*.pl *.py
SHEBANG_FILES=	Tools/C_scripts/mkdep

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	AMReX_ENABLE_TESTS

CMAKE_TESTING_ON=	AMReX_ENABLE_TESTS

BINARY_ALIAS=		mpiexec=${MPIEXEC}

OPTIONS_DEFINE=		PLOTFILE_TOOLS
OPTIONS_DEFAULT=	PLOTFILE_TOOLS

PLOTFILE_TOOLS_DESC=		Enable Plotfile tools # project fails to build/indtall additional executables when this option is enabled
PLOTFILE_TOOLS_CMAKE_ON=	AMReX_PLOTFILE_TOOLS

# tests as of 26.06: 100% tests passed, 0 tests failed out of 67

.include <bsd.port.mk>
