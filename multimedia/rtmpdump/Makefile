# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.4.20130923
PORTREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP streams download utility

LICENSE=	GPLv2

LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp

USES=		pkgconfig
USE_OPENSSL=	yes
MAKE_ENV=	THREADLIB="${PTHREAD_LIBS}"
CFLAGS+=	${PTHREAD_CFLAGS} -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
