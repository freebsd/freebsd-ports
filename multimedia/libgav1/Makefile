PORTNAME=	libgav1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Main profile (0) & High profile (1) compliant AV1 decoder
WWW=		https://chromium.googlesource.com/codecs/libgav1

LICENSE=	APACHE20

LIB_DEPENDS=	libabsl_synchronization.so:devel/abseil

USES=		cmake:testing compiler:c++17-lang localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	jbeich # mirror
GH_TUPLE=	google:googletest:release-1.11.0:gtest/third_party/googletest
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	LIBGAV1_ENABLE_TESTS
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (abseil deps)

.include <bsd.port.mk>
