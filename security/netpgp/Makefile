# $FreeBSD$

PORTNAME=	netpgp
PORTVERSION=	20140220
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/LOCAL_PORTS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP signing, verification, encryption, and decryption program

USES=		libtool ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct rsa_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct rsa_st'
.endif

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC} -Wno-error
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.post.mk>
