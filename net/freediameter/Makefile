PORTNAME=	freediameter
PORTVERSION=	1.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.freediameter.net/hg/freeDiameter/archive/
DISTNAME=	${PORTNAME:S/d/D/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Diameter protocol implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn

USES=		bison cmake tar:bzip2
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DSCTP_USE_MAPPED_ADDRESSES:BOOL=ON
CMAKE_ARGS+=	-DDISABLE_SCTP:BOOL=ON
TEST_TARGET=	test

.include <bsd.port.mk>
