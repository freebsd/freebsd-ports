# ex:ts=8
# Ports collection makefile for:	intk
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti
PORTVERSION=	1.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of C++ classes for developing GNOME and GTK+ applications

USE_GNOME=	glib20 gtk20 atk pango gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/inti-demo \
		lib/libinti-1.0.so lib/libinti-1.0.so.9 \
		lib/inti-1.0/include/inti-config.h \
		libdata/pkgconfig/inti-1.0.pc
PLIST_DIRS=	lib/inti-1.0/include lib/inti-1.0

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-config.h.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif
	@${FIND} ${PREFIX}/include/inti-1.0 -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/inti-1.0 -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/gnome/inti -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/gnome/inti -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
