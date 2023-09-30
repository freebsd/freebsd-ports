PORTNAME=	liveMedia
DISTVERSION=	2022.06.16
PORTEPOCH=	2
CATEGORIES=	net devel
MASTER_SITES=	http://www.live555.com/liveMedia/public/ \
		https://download.videolan.org/contrib/live555/
DISTNAME=	live.${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LIVE.COM Streaming Media
WWW=		http://www.live555.com/liveMedia/

LICENSE=	LGPL21 MAT
LICENSE_COMB=	multi
LICENSE_NAME_MAT=	dated material
LICENSE_TEXT_MAT=	dated material
LICENSE_PERMS_MAT=	pkg-mirror dist-mirror auto-accept

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
