# ex:ts=8
# Ports collection makefile for:	intk-gl
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-gl
PORTVERSION=	0.9
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GtkGLExt, the Open-GL extension to GTK+

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti \
		gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		yes
USE_GNOME=	gnomehack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	lib/libinti-gl-1.0.so lib/libinti-gl-1.0.so.0 \
		lib/inti-1.0/include/inti-gl-config.h \
		libdata/pkgconfig/inti-gl-1.0.pc

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-gl-config.h.in

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
	@${ECHO_CMD} "include/inti-1.0/inti/inti-gl.h" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/inti-1.0/inti/gdk/gl -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gdk/gl/private" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gdk/gl" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/inti-1.0/inti/gtk/gl -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gtk/gl" >> ${TMPPLIST}

.include <bsd.port.mk>
