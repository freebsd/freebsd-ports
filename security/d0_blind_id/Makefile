# $FreeBSD$

PORTNAME=	d0_blind_id
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	security devel

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Crypto library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USE_GITHUB=	yes
GH_ACCOUNT=	divVerent

USES=		autoreconf libtool localbase pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libd0_rijndael.so.0

.include <bsd.port.mk>
