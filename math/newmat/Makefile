PORTNAME=	newmat
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.robertnz.net/ftp/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	C++ matrix library

NO_WRKSUBDIR=	yes
USES=		gmake
USE_LDCONFIG=	yes
MAKEFILE=	nm_gnu.mak
CXXFLAGS+=	-fPIC
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
ALL_TARGET=	everything

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libnewmat.so.1 ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnewmat.so.1
	${LN} -sf libnewmath.so.1 ${STAGEDIR}${PREFIX}/lib/libnewmat.so

.include <bsd.port.mk>
