# ex:ts=8
# Ports collection makefile for:	intk-sourceview
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-sourceview
PORTVERSION=	0.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GtkSourceView

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti

USE_GNOME=	gtksourceview gnomehack gnomeprefix
WRKSRC=		${WRKDIR}/lib${PKGNAME}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	lib/libinti-sourceview-1.0.so lib/libinti-sourceview-1.0.so.0 \
		lib/inti-1.0/include/inti-sourceview-config.h \
		libdata/pkgconfig/inti-sourceview-1.0.pc

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-sourceview-config.h.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
	@${ECHO_CMD} "include/inti-1.0/inti/inti-sourceview.h" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/inti-1.0/inti/gtk-sourceview -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gtk-sourceview/private" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gtk-sourceview" >> ${TMPPLIST}

.include <bsd.port.mk>
