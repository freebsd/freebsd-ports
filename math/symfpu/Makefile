PORTNAME=	symfpu
DISTVERSION=	g20260513
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of IEEE-754 / SMT-LIB floating-point
WWW=		https://github.com/martin-cs/symfpu

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	martin-cs
GH_TAGNAME=	40bdec00e99f8ea1b96c3dac0a05eed11c541639

ALL_TARGET=	subdirs symfpu.a
MAKE_ARGS=	SUBDIRS=baseTypes

# these flags are x86-only and have been patched out
# of ${WRKSRC}/flags for portability
CXXFLAGS_amd64=	-msse -mfma -mno-fma4 -mfpmath=sse
CXXFLAGS_i386=	${CXXFLAGS_amd64}
CXXFLAGS+=	${CXXFLAGS_${ARCH}} -I${WRKSRC}

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/include/symfpu/core \
		${STAGEDIR}${PREFIX}/include/symfpu/utils
	${CP} ${WRKSRC}/core/*.h ${STAGEDIR}${PREFIX}/include/symfpu/core
	${CP} ${WRKSRC}/utils/*.h ${STAGEDIR}${PREFIX}/include/symfpu/utils
	${INSTALL_DATA} ${WRKSRC}/symfpu.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
