PORTNAME=	asclock-xlib
PORTVERSION=	2.0.12
PORTREVISION=	0
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	AFTERSTEP/apps/asclock
DISTNAME=	asclock-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	New flavor of asclock
WWW=		https://web.archive.org/web/20000816095347/http://www.asclock.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	xpm xext x11

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

post-patch:
	${MV} ${WRKSRC}/asclock.man ${WRKSRC}/asclock-xlib.man
	${REINPLACE_CMD} -e s@/usr/local/@${PREFIX}/@ \
		-e s@/usr/share/asclock@${DATADIR}@ \
		${WRKSRC}/config.c

pre-configure:
	(cd ${WRKSRC}; \
	  ${RM} -r default_theme; \
	  ${LN} -s themes/classic default_theme)

post-install:
.for i in Freeamp Newstone Orb Stone beats classic penguin shaped
	(cd ${WRKSRC}/themes/${i}; \
	  ${MKDIR} ${STAGEDIR}${DATADIR}/${i}; \
	  ${INSTALL_DATA} *.xpm config ${STAGEDIR}${DATADIR}/${i}/ )
.endfor

.include <bsd.port.post.mk>
