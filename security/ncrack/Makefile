# Created by: David E. Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ncrack
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://nmap.org/ncrack/dist/ \
				http://redundancy.redundancy.org/mirror/
DISTNAME=	${PORTNAME}-${PORTVERSION}ALPHA

MAINTAINER=	lx@FreeBSD.org
COMMENT=	High-speed network authentication cracking tool

GNU_CONFIGURE=	yes
USES=		gmake ssl
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
