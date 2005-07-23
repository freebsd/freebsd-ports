# ex:ts=8
# Ports collection makefile for:	intk-gl
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-gl
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GtkGLExt, the Open-GL extension to GTK+

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti \
		gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_GL=		yes
USE_GNOME=	gnomehack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-gl-config.h.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
