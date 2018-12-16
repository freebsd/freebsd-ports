# $FreeBSD$

PORTNAME=	CombBLAS
DISTVERSION=	1.6.2
CATEGORIES=	math
MASTER_SITES=	https://people.eecs.berkeley.edu/~aydin/${PORTNAME}_FILES/
DISTNAME=	${PORTNAME}_beta_${DISTVERSION:S/.//:S/./_/}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Combinatorial BLAS library: an extensible parallel graph library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmpi.so:net/mpich
RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so.1:lang/gcc${GCC_DEFAULT} # because of the link flags induced by mpich

USES=		cmake:outsource localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
LDFLAGS+=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libomp.so

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

post-extract:
	@cd ${WRKSRC}/include && ${RM} .DS_Store ._.DS_Store CombBLAS/._CombBLAS.h

.include <bsd.port.mk>
