# New ports collection makefile for:   gtkada
# Date Created:			27 Nov 2000
# Whom:				Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gtkada
PORTVERSION=	1.2.10
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtkada.eu.org/
DISTNAME=	GtkAda-${PORTVERSION}

MAINTAINER=	sam@inf.enst.fr

LIB_DEPENDS=	GLU.14:${PORTSDIR}/graphics/Mesa3
BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat \
		gdk-pixbuf-config:${PORTSDIR}/graphics/gdk-pixbuf

USE_AUTOCONF=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAN_MAN1=	dgate.1 gate.1 gtkada-config.1

post-install:
	${INSTALL_DATA}	${WRKSRC}/docs/*.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gtkada
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_rm/*.info* ${PREFIX}/info/
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_rm/*.html ${PREFIX}/share/doc/gtkada
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_rm/*.ps ${PREFIX}/share/doc/gtkada
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_ug/*.info* ${PREFIX}/info/
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_ug/*.html ${PREFIX}/share/doc/gtkada
	${INSTALL_DATA} ${WRKSRC}/docs/gtkada_ug/*.ps ${PREFIX}/share/doc/gtkada
.endif

.include <bsd.port.mk>
