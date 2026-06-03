PORTNAME=	libyang
PORTVERSION=	3.13.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMESUFFIX=	3

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	YANG data modeling language library, version 3
WWW=		https://github.com/CESNET/libyang

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=	cmake compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CESNET

CONFLICTS=	libyang libyang2

TEST_TARGET=	test

OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.mk>
