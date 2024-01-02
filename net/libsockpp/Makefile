PORTNAME=	libsockpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	net devel

MAINTAINER=	peter@flytrace.com
COMMENT=	Simple, modern, C++ socket library
WWW=		https://github.com/fpagliughi/sockpp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fpagliughi
GH_PROJECT=	sockpp

OPTIONS_DEFINE=		DOCS EXAMPLES STATIC TEST
OPTIONS_DEFAULT=	EXAMPLES STATIC

DOCS_DESC=	Create and install the HTML based API documentation (requires Doxygen)
STATIC_DESC=	Build the static library
EXAMPLES_DESC=	Build example programs
TEST_DESC=	Build the unit tests (requires Catch2)

STATIC_CMAKE_BOOL=	SOCKPP_BUILD_STATIC
EXAMPLES_CMAKE_BOOL=	SOCKPP_BUILD_EXAMPLES
TEST_BUILD_DEPENDS=	catch2>0:devel/catch2
TEST_CMAKE_BOOL=	SOCKPP_BUILD_TESTS

OPTIONS_SUB=		yes
EXAMPLES_TO_REMOVE=	tcp6echo \
			tcp6echosvr \
			tcpecho \
			tcpechomt \
			tcpechosvr \
			tcpechotest \
			udp6echo \
			udpecho \
			udpechosvr \
			undgramecho \
			undgramechosvr \
			unecho \
			unechosvr \
			unechotest

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${RM} ${EXAMPLES_TO_REMOVE}

.include <bsd.port.mk>
