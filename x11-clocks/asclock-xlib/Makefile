# New ports collection makefile for:	asclock-xlib
# Version required:	2.0.11
# Date created:		24 April 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	asclock-xlib-2.0.11
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

HAS_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/asclock-xlib
USE_X_PREFIX=	YES

post-patch:
	@(cd ${WRKSRC}; \
	  ${MV} config.c config.c.tmp; \
	  ${SED} -e s@/usr/local/@${X11BASE}/@ -e s@/usr/share/asclock@${LOCALBASE}/share/asclock@ < config.c.tmp > config.c )

.if defined(BATCH)
do-configure:
	@(cd ${WRKSRC}; \
	  ${RM} -rf default_theme; \
	  ${LN} -s themes/Orb default_theme; \
	  ${XMKMF} )
.endif

post-install:
.for i in Freeamp Newstone Orb Stone beats classic penguin shaped
	(cd ${WRKSRC}/themes/${i}; \
	  ${MKDIR} ${PREFIX}/share/asclock/${i}; \
	  ${INSTALL_DATA} *.xpm config ${PREFIX}/share/asclock/${i}/ )
.endfor

.include <bsd.port.mk>
