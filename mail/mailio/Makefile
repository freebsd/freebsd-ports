PORTNAME=	mailio
DISTVERSION=	0.23.0-59
DISTVERSIONSUFFIX=	-g5dab3ca
CATEGORIES=	mail devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for MIME format and SMTP, POP3 and IMAP protocols
WWW=		https://github.com/karastojko/mailio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:testing compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	karastojko

CMAKE_OFF=	MAILIO_BUILD_TESTS MAILIO_BUILD_EXAMPLES MAILIO_BUILD_DOCUMENTATION
CMAKE_TESTING_ON=	MAILIO_BUILD_TESTS # tests fail to link, see https://github.com/karastojko/mailio/issues/159

.include <bsd.port.mk>
