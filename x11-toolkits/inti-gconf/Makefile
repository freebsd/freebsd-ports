# ex:ts=8
# Ports collection makefile for:	intk-gconf
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-gconf
PORTVERSION=	1.0.5
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GConf, the GNOME Configuration System

DEPRECATED=	not maintain by upstream for more than five years and no port depend on this
EXPIRATION_DATE=2009-02-11

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti

USE_GNOME=	gconf2 gnomehack gnomeprefix
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-gconf-config.h.in

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
