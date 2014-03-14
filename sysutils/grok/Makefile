# $FreeBSD$

PORTNAME=	grok
PORTVERSION=	1.20110708.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Expert system for real-time log analysis

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	gperf>=3.0.3:${PORTSDIR}/devel/gperf
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libevent-2.0.so:${PORTSDIR}/devel/libevent2 \
		libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_ENV+=	GPERF=${LOCALBASE}/bin/gperf \
		EXTRA_CFLAGS=-I${LOCALBASE}/include \
		EXTRA_LDFLAGS=-L${LOCALBASE}/lib

USES=		gmake pkgconfig
USE_LDCONFIG=	yes
LDFLAGS+=	`pkgconf --libs libevent`
CFLAGS+=	`pkgconf --cflags libevent`

SUB_FILES=	pkg-message

PROJECTHOST=	semicomplete
PORTDOCS=	CHANGELIST INSTALL

post-patch:
	@${REINPLACE_CMD} 's|PREFIX=|PREFIX?=|; s|-g root|-g wheel|; s|-levent||g' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/grok.1 ${STAGEDIR}${PREFIX}/man/man1
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
