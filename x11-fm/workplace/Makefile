# New ports collection makefile for:	workplace
# Date created:				7 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	workplace
PORTVERSION= 	1.0.a3
CATEGORIES=	x11-fm
MASTER_SITES=	http://people.freebsd.org/~trevor/ports/distfiles/

MAINTAINER=	trevor@FreeBSD.org

BROKEN=		"patches are not yet correct"

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/glib12 \
		-I${X11BASE}/include/gtk12" \
		LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@ ${RM} ${WRKSRC}/config.cache

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/workplace ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/include/X11/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
	@ ${MKDIR} ${PREFIX}/share/doc/workplace
.for file in AUTHORS INSTALL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/workplace
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/workplace
	@ ${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/workplace

.include <bsd.port.mk>
