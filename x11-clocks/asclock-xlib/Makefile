# New ports collection makefile for:	asclock-xlib
# Date created:		24 April 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asclock-xlib
PORTVERSION=	2.0.11
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	New flavor of asclock

WRKSRC=		${WRKDIR}/asclock-xlib
USE_XPM=	YES
MAN1=		asclock.1

.if defined(BATCH)
USE_IMAKE=	YES
.else
USE_X_PREFIX=	YES
HAS_CONFIGURE=	YES
.endif

.include <bsd.port.pre.mk>

post-patch:
	@(cd ${WRKSRC}; \
	  ${MV} config.c config.c.tmp; \
	  ${SED} -e s@/usr/local/@${PREFIX}/@ -e s@/usr/share/asclock@${PREFIX}/share/asclock@ < config.c.tmp > config.c )

.if defined(BATCH)
pre-configure:
	@(cd ${WRKSRC}; \
	  ${RM} -rf default_theme; \
	  ${LN} -s themes/Orb default_theme)
.endif

post-install:
.for i in Freeamp Newstone Orb Stone beats classic penguin shaped
	(cd ${WRKSRC}/themes/${i}; \
	  ${MKDIR} ${PREFIX}/share/asclock/${i}; \
	  ${INSTALL_DATA} *.xpm config ${PREFIX}/share/asclock/${i}/ )
.endfor

.include <bsd.port.post.mk>
