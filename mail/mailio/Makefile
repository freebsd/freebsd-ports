PORTNAME=	mailio
DISTVERSION=	0.25.1
PORTREVISION=	2
CATEGORIES=	mail devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for MIME format and SMTP, POP3 and IMAP protocols
WWW=		https://github.com/karastojko/mailio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	karastojko

CMAKE_OFF=	MAILIO_BUILD_TESTS MAILIO_BUILD_EXAMPLES MAILIO_BUILD_DOCUMENTATION
CMAKE_ON=	MAILIO_DYN_LINK_TESTS # workaround for https://github.com/karastojko/mailio/issues/159
CMAKE_TESTING_ON=	MAILIO_BUILD_TESTS # tests fail, see https://github.com/karastojko/mailio/issues/160
CMAKE_TESTING_TARGET=	all

post-test:
	@cd ${WRKSRC}/test && ${BUILD_WRKSRC}/test/test_message

# tests as of 0.25.1:
# Running 139 test cases...
# *** No errors detected

.include <bsd.port.mk>
