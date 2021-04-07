PORTNAME=	HipMCL
DISTVERSION=	g20180814
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance parallel algorithm for large-scale network clustering

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libCombBLAS.so:math/combblas \
		libmpi.so:net/mpich
RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so.1:lang/gcc${GCC_DEFAULT} # because of the link flags induced by mpich

USES=		cmake compiler:c++14-lang dos2unix localbase:ldflags
DOS2UNIX_FILES=	CMakeLists.txt

BB_ACCOUNT=	azadcse
BB_PROJECT=	${PORTNAME:tl}
BB_COMMIT=	e20476acc473

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_FILES=	bin/${PORTNAME:tl}

post-extract:
	@${RM} -r ${WRKSRC}/src/CombBLAS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/hipmcl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
