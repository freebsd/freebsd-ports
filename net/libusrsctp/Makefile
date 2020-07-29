# $FreeBSD$

PORTNAME=	libusrsctp
DISTVERSION=	0.9.3.0-856
DISTVERSIONSUFFIX=	-g66a25d7
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable SCTP userland stack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	sctplab
GH_PROJECT=	usrsctp
USE_LDCONFIG=	yes

PLIST_FILES=	include/usrsctp.h \
		lib/libusrsctp.a \
		lib/libusrsctp.so \
		lib/libusrsctp.so.1 \
		lib/libusrsctp.so.1.0.0

CFLAGS+=	-Wno-error

.include <bsd.port.mk>
