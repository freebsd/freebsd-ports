# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	liveMedia
PORTVERSION=	2019.11.06
PORTEPOCH=	2
CATEGORIES=	net devel
MASTER_SITES=	http://www.live555.com/liveMedia/public/ \
		https://download.videolan.org/contrib/live555/
DISTNAME=	live.${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LIVE.COM Streaming Media

LICENSE=	LGPL21

NO_CDROM=	'dated material'

BROKEN_sparc64=		Fails to compile

WRKSRC=		${WRKDIR}/live

HAS_CONFIGURE=	yes

CONFIGURE_SCRIPT=	genMakefiles
CONFIGURE_ARGS=		fixed-freebsd

USES=		compiler:c++11-lang gmake
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
.endif

post-extract:
	${CP} ${FILESDIR}/config.fixed-freebsd ${WRKSRC}

.if ${PREFIX} != "/usr/local"
post-configure:
	${REINPLACE_CMD} -e 's,^PREFIX = /usr/local,PREFIX = "${PREFIX}",' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile
.endif

.include <bsd.port.post.mk>
