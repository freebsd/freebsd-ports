# Ports collection makefile for:	rtmpdump
# Date created:				March 15, 2010
# Whom:					hrs
#
# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A tool to download RTMP streams

MAN1=		rtmpdump.1
MAN3=		librtmp.3
MAN8=		rtmpgw.8

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
MAKE_ENV=	CFLAGS="${PTHREAD_CFLAGS}" THREADLIB="${PTHREAD_LIBS}"
PORTDOCS=	ChangeLog README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.if ${OPENSSLBASE} != "/usr"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
