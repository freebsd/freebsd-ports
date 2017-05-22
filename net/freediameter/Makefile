# $FreeBSD$

PORTNAME=	freeDiameter
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.freediameter.net/hg/freeDiameter/archive/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Open source Diameter protocol implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn

BROKEN_powerpc64=	fails to build: CMake Error at CMakeLists.txt: Unable to find idna.h header or idna_to_ascii_8z function

USES=		cmake bison
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DSCTP_USE_MAPPED_ADDRESSES:BOOL=ON

.include <bsd.port.mk>
