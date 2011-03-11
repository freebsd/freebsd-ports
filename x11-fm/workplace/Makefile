# New ports collection makefile for:	workplace
# Date created:				7 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	workplace
PORTVERSION=	1.0.a3
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

PATCH_SITES=	http://people.freebsd.org/~trevor/ports/
PATCHFILES=	workplace-1.0.a3+tj1.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File manager and launcher

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/glib12 \
		-I${LOCALBASE}/include/gtk12" \
		LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@ ${RM} ${WRKSRC}/config.cache

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/workplace ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/include/X11/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
.if !defined(NOPORTDOCS)
.for file in AUTHORS INSTALL README TODO
	@ ${MKDIR} ${PREFIX}/share/doc/workplace
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
