# $FreeBSD$

PORTNAME=	usockets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Miniscule eventing, networking & crypto for async applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=	error: unknown type name 'u_short'; did you mean 'short'?, etc
BROKEN_riscv64=		fails to build: Hard-float 'd' ABI can't be used for a target that doesn't support the D instruction set extension

USES=		compiler:c++17-lang gmake ssl # c++17 only for temp C_++ code, otherwise it is c11
USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uSockets
USE_LDCONFIG=	yes

MAKE_ARGS=	WITH_OPENSSL=1

ALL_TARGET=	default

PLIST_FILES=	include/libusockets.h \
		lib/libuSockets.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libusockets.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libuSockets.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
