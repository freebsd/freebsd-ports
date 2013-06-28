# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asclock-xlib
PORTVERSION=	2.0.11
PORTREVISION=	3
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	New flavor of asclock

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/asclock-xlib
USE_XORG=	xpm x11
USES=		imake

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	YES
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
	cd ${WRKSRC} && ${MAKE} install.man

.include <bsd.port.post.mk>
