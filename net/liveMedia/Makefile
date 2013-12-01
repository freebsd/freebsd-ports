# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	liveMedia
PORTVERSION=	2013.11.29
PORTEPOCH=	2
CATEGORIES=	net devel
MASTER_SITES=	LOCAL/wg \
		http://www.live555.com/liveMedia/public/
DISTNAME=	live.${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LIVE.COM Streaming Media

LICENSE=	LGPL21

NO_CDROM=	'dated material'

WRKSRC=		${WRKDIR}/live

HAS_CONFIGURE=	yes

CONFIGURE_SCRIPT=	genMakefiles
CONFIGURE_ARGS=		fixed-${OPSYS:L}

USES=		gmake
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-extract:
	${CP} ${FILESDIR}/config.fixed-${OPSYS:L} ${WRKSRC}/

.include <bsd.port.post.mk>
