# $FreeBSD$

PORTNAME=	librtmp
PORTVERSION=	2.4.20151223
CATEGORIES=	multimedia net
MASTER_SITES=	LOCAL/hrs
DISTNAME=	rtmpdump-2.4.fa8646da

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP stream library

LICENSE=	GPLv2

USES=		pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
WRKSRC=		${WRKDIR}/${DISTNAME}/librtmp

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
