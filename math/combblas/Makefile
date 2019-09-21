# $FreeBSD$

PORTNAME=	CombBLAS
DISTVERSION=	1.6.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://people.eecs.berkeley.edu/~aydin/${PORTNAME}_FILES/
DISTNAME=	${PORTNAME}_beta_${DISTVERSION:S/.//:S/./_/}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Combinatorial BLAS library: an extensible parallel graph library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmpi.so:net/mpich \
		libomp.so:devel/openmp
RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so.1:lang/gcc${GCC_DEFAULT} # because of the link flags induced by mpich

USES=		cmake compiler:c++14-lang localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-extract:
	@cd ${WRKSRC}/include && ${RM} .DS_Store ._.DS_Store CombBLAS/._CombBLAS.h

.include <bsd.port.mk>
