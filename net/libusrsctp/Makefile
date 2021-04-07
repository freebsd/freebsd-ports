PORTNAME=	libusrsctp
DISTVERSION=	0.9.5.0
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable SCTP userland stack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sctplab
GH_PROJECT=	usrsctp

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/usrsctp.h \
		lib/libusrsctp.so \
		lib/libusrsctp.so.2 \
		lib/libusrsctp.so.2.0.0 \
		libdata/pkgconfig/usrsctp.pc

CFLAGS+=	-Wno-error

.include <bsd.port.mk>
