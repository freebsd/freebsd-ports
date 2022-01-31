# Created by: Alex Dupre <ale@FreeBSD.org>

PORTNAME=	secp256k1
PORTVERSION=	0.1.20220126
CATEGORIES=	math security java

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Optimized C library for EC operations on curve secp256k1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bitcoin-core
GH_TAGNAME=	d8a2463

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-experimental --enable-module-ecdh \
		--enable-module-recovery --enable-module-extrakeys \
		--enable-module-schnorrsig
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
