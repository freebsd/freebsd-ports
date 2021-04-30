PORTNAME=	opennn
DISTVERSION=	5.0.5
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/Artelnics/opennn/archive/refs/tags/v${DISTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open neural networks library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler dos2unix zip
DOS2UNIX_FILES=	opennn/CMakeLists.txt
USE_LDCONFIG=	yes

CMAKE_OFF=	OpenNN_BUILD_EXAMPLES OpenNN_BUILD_TESTS
LDFLAGS+=	-lomp -pthread # https://github.com/Artelnics/opennn/issues/182

OPTIONS_DEFINE=		MPI

MPI_CMAKE_BOOL=		__OPENNN_MPI__
MPI_BROKEN=		deactivated: https://github.com/Artelnics/OpenNN/issues/86

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME} && ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}/libopennn.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopennn.so

.include <bsd.port.mk>
