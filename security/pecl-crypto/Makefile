PORTNAME=	crypto
PORTVERSION=	0.3.2
CATEGORIES=	security

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Objective wrapper for OpenSSL Crypto Library
WWW=		https://pecl.php.net/package/crypto

LICENSE=	PHP301

USES=		compiler:c++11-lang php:pecl ssl

CONFIGURE_ARGS=	--with-crypto

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
