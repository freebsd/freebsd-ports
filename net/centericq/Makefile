# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	3.13.3
CATEGORIES=	net
MASTER_SITES=	http://download.konst.org.ua/

MAINTAINER=	ijliao@csie.nctu.edu.tw

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-nostdinc -I${LOCALBASE}/include/ncurses \
		-I${LOCALBASE}/include -I/usr/include
.endif

LIB_DEPENDS=	icq.0:${PORTSDIR}/net/libicq

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.post.mk>
