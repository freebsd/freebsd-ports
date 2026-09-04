PORTNAME=	freediameter
PORTVERSION=	1.6.0
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Diameter protocol implementation
WWW=		https://github.com/freeDiameter/freeDiameter/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn2.so:dns/libidn2

USES=		bison cmake:testing cpe pkgconfig tar:bzip2

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	freeDiameter
GH_PROJECT=	freeDiameter

CMAKE_ON=	SCTP_USE_MAPPED_ADDRESSES \
		DISABLE_SCTP

.include <bsd.port.mk>
