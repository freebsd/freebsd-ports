PORTNAME=	secp256k1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	math security java

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Optimized C library for EC operations on curve secp256k1
WWW=		https://github.com/bitcoin-core/secp256k1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bitcoin-core

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-module-recovery
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
