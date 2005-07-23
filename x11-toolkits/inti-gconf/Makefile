# ex:ts=8
# Ports collection makefile for:	intk-gconf
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-gconf
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GConf, the GNOME Configuration System

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_GNOME=	gconf2 gnomehack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

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
