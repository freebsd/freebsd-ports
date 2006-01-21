# New ports collection makefile for:	workplace
# Date created:				7 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	workplace
PORTVERSION=	1.0.a3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

PATCH_SITES=	http://people.freebsd.org/~trevor/ports/
PATCHFILES=	workplace-1.0.a3+tj1.diff.gz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	File manager and launcher

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
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
.if !defined(NOPORTDOCS)
.for file in AUTHORS INSTALL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/workplace
.endfor
.endif
	@ ${MKDIR} ${PREFIX}/share/examples/workplace
	@ ${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/workplace

.include <bsd.port.mk>
