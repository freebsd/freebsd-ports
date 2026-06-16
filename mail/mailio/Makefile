PORTNAME=	mailio
DISTVERSION=	0.26.0
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

CMAKE_OFF=	MAILIO_BUILD_TESTS \
		MAILIO_DYN_LINK_TESTS \
		MAILIO_BUILD_EXAMPLES \
		MAILIO_BUILD_DOCUMENTATION
CMAKE_TESTING_ON=	MAILIO_BUILD_TESTS \
			MAILIO_DYN_LINK_TESTS
CMAKE_TESTING_TARGET=	all

LDFLAGS+=	-lpthread

post-test:
	@cd ${WRKSRC}/test && ${BUILD_WRKSRC}/test/test_message

# tests as of 0.26.0:
# Running 142 test cases...
# *** No errors detected

.include <bsd.port.mk>
