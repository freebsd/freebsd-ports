# Created by: Gasol Wu <gasol.wu@gmail.com>

PORTNAME=	crypto
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Objective wrapper for OpenSSL Crypto Library

LICENSE=	PHP301

USES=		compiler:c++11-lang php:pecl
IGNORE_WITH_PHP=	80 81
CONFIGURE_ARGS=	--with-crypto
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
