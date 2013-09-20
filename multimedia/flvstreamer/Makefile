# Created by: hrs
# $FreeBSD$

PORTNAME=	flvstreamer
PORTVERSION=	2.1.c.1
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}/source
DISTNAME=	${PORTNAME}-2.1c1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An open source command-line RTMP client

USE_GMAKE=	yes
ALL_TARGET=	posix
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	THREADLIB="${PTHREAD_LIBS}" \
		XCFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		XLDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/flvstreamer bin/streams
PORTDOCS=	ChangeLog ChangeLog.rtmpdump README

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:S,^bin/,,} \
		${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
