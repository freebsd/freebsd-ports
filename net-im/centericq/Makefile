# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	3.22.8
CATEGORIES=	net
MASTER_SITES=	http://download.konst.org.ua/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-nostdinc -I${LOCALBASE}/include/ncurses \
		-I${LOCALBASE}/include -I/usr/include
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.post.mk>
