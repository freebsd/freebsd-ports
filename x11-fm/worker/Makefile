# New ports collection makefile for:	worker
# Date created:				14 March 2001
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	worker
PORTVERSION=	2.7.0
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/worker/downloads/ \
		http://www.informatik.uni-halle.de/~hoffmanr/worker/downloads/

MAINTAINER=	simond@irrelevant.org

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes

MAN1=		worker.1

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-libxpkmaster

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
