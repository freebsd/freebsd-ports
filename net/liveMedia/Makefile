# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	liveMedia
PORTVERSION=	2020.04.24
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

USES=		compiler:c++11-lang gmake ssl
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
.endif

post-extract:
	${CP} ${FILESDIR}/config.fixed-freebsd ${WRKSRC}

post-patch:
	# LIBS_FOR_CONSOLE_APPLICATION = -lssl -lcrypto
	${REINPLACE_CMD} '/LIBS_FOR_CONSOLE_APPLICATION/s|$$|-L${OPENSSLLIB} -lssl -lcrypto|' \
		${WRKSRC}/config.fixed-freebsd

.if ${PREFIX} != "/usr/local"
post-configure:
	${REINPLACE_CMD} -e 's,^PREFIX = /usr/local,PREFIX = "${PREFIX}",' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile
.endif

.include <bsd.port.post.mk>
