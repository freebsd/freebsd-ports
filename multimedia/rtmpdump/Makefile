# Ports collection makefile for:	rtmpdump
# Date created:				March 15, 2010
# Whom:					hrs
#
# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.2d
CATEGORIES=	multimedia net
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A tool to download RTMP streams

USE_GMAKE=	yes
ALL_TARGET=	posix

MAN1=		rtmpdump.1
MAN8=		rtmpgw.8

PLIST_FILES=	bin/rtmpdump bin/rtmpgw bin/rtmpsrv bin/rtmpsuck
PORTDOCS=	ChangeLog README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:S,^bin/,,} \
		${PREFIX}/bin \
		&& ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1 \
		&& ${INSTALL_MAN} ${MAN8} ${MAN1PREFIX}/man/man8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
