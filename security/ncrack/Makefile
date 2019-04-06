# Created by: David E. Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ncrack
DISTVERSION=	0.6
CATEGORIES=	security
MASTER_SITES=	http://nmap.org/ncrack/dist/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	High-speed network authentication cracking tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake ssl
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}.0

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	Your OpenSSL headers do not match your library
BROKEN_FreeBSD_13=	Your OpenSSL headers do not match your library
.endif

.include <bsd.port.post.mk>
