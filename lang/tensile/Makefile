# ex:ts=8
# Ports collection makefile for:	nsl
# Date created:			May 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nsl
PORTVERSION=	0.9
CATEGORIES=	lang
MASTER_SITES=	http://savannah.gnu.org/download/nsl/ \
		http://iling.nw.ru/~artem/downloads/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	utils:${PORTSDIR}/lang/libutils

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
