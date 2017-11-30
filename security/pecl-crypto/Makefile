# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	crypto
PORTVERSION=	0.3.1
CATEGORIES=	security

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Objective wrapper for OpenSSL Crypto Library

LICENSE=	PHP301

BROKEN_armv6=		fails to configure: C compiler cannot create executables
BROKEN_armv7=		fails to configure: C compiler cannot create executables
BROKEN_mips=		fails to configure: C compiler cannot create executables
BROKEN_mips64=		fails to configure: C compiler cannot create executables
BROKEN_powerpc64=	fails to configure: C compiler cannot create executables

USES=		php:pecl
CONFIGURE_ARGS=	--with-crypto
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
