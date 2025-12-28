PORTNAME=	libgav1
DISTVERSION=	0.20.0
CATEGORIES=	multimedia
MASTER_SITES=	DEBIAN:DEFAULT \
		https://github.com/google/googletest/releases/download/v1.15.2/:googletest
DISTFILES=	${PORTNAME}_${DISTVERSION}.orig${EXTRACT_SUFX}:DEFAULT \
		googletest-1.15.2.tar.gz:googletest

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Main profile (0) & High profile (1) compliant AV1 decoder
WWW=		https://chromium.googlesource.com/codecs/libgav1

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libabsl_synchronization.so:devel/abseil

USES=		cmake:testing compiler:c++17-lang localbase:ldflags tar:xz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

LDFLAGS+=	-Wl,--as-needed

CMAKE_TESTING_ON=	LIBGAV1_ENABLE_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	CMAKE_CXX_EXTENSIONS \
		LIBGAV1_ENABLE_TESTS

post-extract:
	@${MKDIR} ${WRKSRC}/third_party
	@${MV} ${WRKDIR}/googletest-1.15.2 ${WRKSRC}/third_party/googletest

.include <bsd.port.mk>
