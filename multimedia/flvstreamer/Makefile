# $FreeBSD$

PORTNAME=	flvstreamer
PORTVERSION=	2.1.c.1
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	SAVANNAH/${PORTNAME}/source
DISTNAME=	${PORTNAME}-2.1c1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open source command-line RTMP client

USES=		gmake
ALL_TARGET=	posix
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	THREADLIB="-lpthread" XCFLAGS="${CFLAGS}" XLDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/flvstreamer bin/streams
PORTDOCS=	ChangeLog ChangeLog.rtmpdump README

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:S,^bin/,,} \
		${STAGEDIR}${PREFIX}/bin

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
