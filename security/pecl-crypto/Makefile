# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	crypto
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Objective wrapper for OpenSSL Crypto Library

LICENSE=	PHP301

USES=		compiler:c++11-lang php:pecl
CONFIGURE_ARGS=	--with-crypto
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
