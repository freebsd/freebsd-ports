PORTNAME=	aeron
DISTVERSION=	1.47.3
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reliable UDP unicast, UDP multicast, and IPC message transport
WWW=		https://aeron.io/ \
		https://github.com/real-logic/aeron

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 # limited in aeron-client/src/main/c/concurrent/aeron_atomic.h

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

TESTING_UNSAFE=	tests as of 1.44.6: 89% tests passed, 15 tests failed out of 131, see https://github.com/real-logic/aeron/issues/1696

.include <bsd.port.mk>
