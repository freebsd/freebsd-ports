# $FreeBSD$

PORTNAME=	usockets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Miniscule eventing, networking & crypto for async applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uSockets
USE_LDCONFIG=	yes

ALL_TARGET=	default

PLIST_FILES=	include/libusockets.h \
		lib/libusockets.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libusockets.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libusockets.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
