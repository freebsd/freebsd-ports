# $FreeBSD$

PORTNAME=	freeDiameter
PORTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.freediameter.net/hg/freeDiameter/archive/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Open source Diameter protocol implementation

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls

USES=		cmake bison
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DSCTP_USE_MAPPED_ADDRESSES:BOOL=ON

.include <bsd.port.mk>
