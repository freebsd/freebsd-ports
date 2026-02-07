PORTNAME=	crypto
DISTVERSION=	0.3.2
CATEGORIES=	security

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Objective wrapper for OpenSSL Crypto Library
WWW=		https://pecl.php.net/package/crypto

LICENSE=	PHP301

USES=		compiler:c++11-lang php:pecl ssl

CONFIGURE_ARGS=	--with-crypto

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${PHP_VER} >= 85
.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string.h|Zend/zend_smart_string.h|' \
		${WRKSRC}/phpc/phpc.h
.endif

.include <bsd.port.post.mk>
