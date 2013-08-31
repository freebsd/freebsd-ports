# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A tool to download RTMP streams

LICENSE=	GPLv2

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
MAKE_ENV=	THREADLIB="${PTHREAD_LIBS}"
CFLAGS+=	${PTHREAD_CFLAGS}
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	ChangeLog README

MAN1=		rtmpdump.1
MAN3=		librtmp.3
MAN8=		rtmpgw.8

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPENSSLBASE} != "/usr"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
