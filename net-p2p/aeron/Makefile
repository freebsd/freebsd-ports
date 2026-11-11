PORTNAME=	aeron
DISTVERSION=	1.54.1
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reliable UDP unicast, UDP multicast, and IPC message transport
WWW=		https://aeron.io/ \
		https://github.com/real-logic/aeron

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le # limited in aeron-client/src/main/c/concurrent/aeron_atomic.h

LIB_DEPENDS=	libuuid.so:misc/libuuid # only for uuid_generate
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	real-logic

CMAKE_OFF=	${CMAKE_TESTING_ON} \
		AERON_BUILD_SAMPLES \
		BUILD_AERON_ARCHIVE_API
CMAKE_OFF+=	FETCHCONTENT_FULLY_DISCONNECTED

CMAKE_TESTING_ON=	AERON_TESTS \
			AERON_UNIT_TESTS \
			AERON_SYSTEM_TESTS \
			AERON_SLOW_SYSTEM_TESTS

LDFLAGS+=	-lm \
		-luuid

CMAKE_TESTING_JOBS=	1

TESTING_UNSAFE=

# tests as of 1.54.1: 100% tests passed, 0 tests failed out of 110
# (the 2 Java client integration tests are excluded on FreeBSD because the
#  gradle build does not reliably locate a suitable JDK in the ports environment)

.include <bsd.port.mk>
