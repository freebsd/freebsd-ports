# Created by: Thibault Payet <monwarez@mailoo.org>
# $FreeBSD$

PORTNAME=	libnitrokey
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6
CATEGORIES=	security
MASTER_SITES=	https://github.com/Nitrokey/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Libnitrokey is a project to communicate with Nitrokey devices

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++14-lang pkgconfig

USE_LDCONFIG=	yes

TEST_TARGET=	test
OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=	COMPILE_OFFLINE_TESTS
TEST_BUILD_DEPENDS=	${LOCALBASE}/include/catch2/catch.hpp:devel/catch

.include <bsd.port.mk>
