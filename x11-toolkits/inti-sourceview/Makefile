# ex:ts=8
# Ports collection makefile for:	intk-sourceview
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-sourceview
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GtkSourceView

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti

USE_GNOME=	gtksourceview gnomehack gnomeprefix
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-sourceview-config.h.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
