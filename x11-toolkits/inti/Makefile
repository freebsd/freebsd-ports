# ex:ts=8
# Ports collection makefile for:	intk
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of C++ classes for developing GNOME and GTK+ applications

USE_GNOME=	glib20 gtk20 atk pango gnomehack gnomeprefix
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

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
	@${FIND} ${PREFIX}/share/gnome/inti -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/gnome/inti -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
