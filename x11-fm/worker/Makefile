# New ports collection makefile for:	worker
# Date created:				14 March 2001
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	worker
PORTVERSION=	2.12.0
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/worker/downloads/

MAINTAINER=	simond@irrelevant.org
COMMENT=	X11 File Manager based on Directory Opus

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes

MAN1=		worker.1

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-libxpkmaster

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
