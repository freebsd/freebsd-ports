PORTNAME=	casadi
DISTVERSION=	3.6.0
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Symbolic framework for numeric optimization
WWW=		https://web.casadi.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcoinmumps.so:math/coin-or-mumps

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

CMAKE_OFF=	WITH_DEEPBIND WITH_BUILD_BLASFEO

# cmake-3.16: disable build of examples (they are not installed anyways),
# and fail due to not setting up the linker environment properly:
CMAKE_OFF+=	WITH_EXAMPLES

OPTIONS_DEFINE=		BLASFEO BONMIN CLANG IPOPT LAPACK QPOASES
OPTIONS_DEFAULT=	BLASFEO BONMIN IPOPT LAPACK QPOASES
OPTIONS_SUB=		yes

BLASFEO_DESC=		Build with BLASFEO
BLASFEO_CMAKE_BOOL=	WITH_BLASFEO
BLASFEO_BUILD_DEPENDS=	blasfeo>0:math/blasfeo

BONMIN_DESC=		Build with Bonmin
BONMIN_CMAKE_BOOL=	WITH_BONMIN
BONMIN_USES=		blaslapack:netlib fortran
BONMIN_LIB_DEPENDS=	libbonmin.so:math/bonmin \
			libCbcSolver.so:math/cbc \
			libCgl.so:math/cgl \
			libClp.so:math/clp \
			libcoinasl.so:math/asl \
			libCoinUtils.so:math/coinutils \
			libipopt.so:math/ipopt \
			libnauty.so:math/nauty \
			libopenblas.so:math/openblas \
			libOsi.so:math/osi

CLANG_DESC=		Build with clang for JIT
CLANG_USES=		llvm:16,build,run
CLANG_CMAKE_BOOL=	WITH_CLANG
CLANG_CMAKE_ON=		-DLLVM_INSTALL_PREFIX=${LLVM_PREFIX} -DOLD_LLVM=ON
CLANG_BROKEN=		fails to find clang, see https://github.com/casadi/casadi/issues/3089

IPOPT_DESC=		Build with IPopt
IPOPT_CMAKE_BOOL=	WITH_IPOPT
IPOPT_USES=		blaslapack:netlib fortran
IPOPT_LIB_DEPENDS=	libipopt.so:math/ipopt

LAPACK_DESC=		Build with LAPACK
LAPACK_CMAKE_BOOL=	WITH_LAPACK
LAPACK_USES=		blaslapack:openblas

QPOASES_DESC=		Build with qpOASES
QPOASES_CMAKE_BOOL=	WITH_QPOASES
QPOASES_LIB_DEPENDS=	libopenblas.so:math/openblas
QPOASES_IMPLIES=	LAPACK

PORTSCOUT=	limit:^.*[1-9]\..* # prevent tags like ge2

.include <bsd.port.mk>
