# ex:ts=8
# Ports collection makefile for:	intk
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/inti/Makefile,v 1.3 2007/05/23 16:18:51 ahze Exp $

PORTNAME=	inti
PORTVERSION=	1.2
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of C++ classes for developing GNOME and GTK+ applications

USE_GNOME=	glib20 gtk20 atk pango gnomehack gnomeprefix
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|_gtk_window_get_group|gtk_window_get_group|' \
	    	${WRKSRC}/inti/gtk/window.cc

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
	@${FIND} ${PREFIX}/share/inti -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/inti -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
