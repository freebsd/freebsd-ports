# $FreeBSD$

PORTNAME=	netpgp
PORTVERSION=	20140220
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/LOCAL_PORTS/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	PGP signing, verification, encryption, and decryption program

USES=		libtool
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-error
.if !exists(/usr/include/openssl/idea.h)
CFLAGS+=	-DOPENSSL_NO_IDEA
.endif

.include <bsd.port.mk>
