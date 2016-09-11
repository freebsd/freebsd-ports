# $FreeBSD$

PORTNAME=	netpgp
PORTVERSION=	20140220
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/LOCAL_PORTS/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	PGP signing, verification, encryption, and decryption program

USES=		libtool ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC} -Wno-error
LDFLAGS+=	-L${OPENSSLLIB}
.if !exists(${OPENSSLINC}/openssl/idea.h)
CFLAGS+=	-DOPENSSL_NO_IDEA
.endif

.include <bsd.port.post.mk>
