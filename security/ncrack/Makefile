# Created by: David E. Thiel <lx@FreeBSD.org>

PORTNAME=	ncrack
DISTVERSION=	0.7
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	High-speed network authentication cracking tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nmap

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_11=	OpenSSL > 1.0 required
.endif

.include <bsd.port.post.mk>
