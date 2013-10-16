# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.4.20130923
CATEGORIES=	multimedia net
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A tool to download RTMP streams

LICENSE=	GPLv2

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
MAKE_ENV=	THREADLIB="${PTHREAD_LIBS}"
CFLAGS+=	${PTHREAD_CFLAGS}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPENSSLBASE} != "/usr"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
