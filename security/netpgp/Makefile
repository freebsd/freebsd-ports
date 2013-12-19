# $FreeBSD$

PORTNAME=	netpgp
PORTVERSION=	20101107
CATEGORIES=	security
MASTER_SITES=	NETBSD/LOCAL_PORTS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP signing, verification, encryption, and decryption program

LICENSE=	BSD

USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-error
.if !exists(/usr/include/openssl/idea.h)
CFLAGS+=-	-DOPENSSL_NO_IDEA
.endif

.include <bsd.port.mk>
