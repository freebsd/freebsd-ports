# New ports collection makefile for:	gnomesu
# Date created:				26 July 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	gnomesu
PORTVERSION=	0.3.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xsu

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gtk frontend to su

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack libgnomeui libzvt

MAN1=		gnomesu.1

.if !defined(NOPORTDOCS)
PORTDOCS=	ABOUT-NLS AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
