# ex:ts=8
# Ports collection makefile for:	tensile
# Date created:			May 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tensile
PORTVERSION=	0.9p8
CATEGORIES=	lang
MASTER_SITES=	http://savannah.gnu.org/download/nsl/ \
		http://iling.nw.ru/~artem/downloads/ \
		http://unixpages.org/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	chris@unixpages.org

LIB_DEPENDS=	utils:${PORTSDIR}/lang/libutils

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
