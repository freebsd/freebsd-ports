# New ports collection makefile for:   FSViewer.app
# Date created:                6. Sept. 2003
# Whom:                        Fritz Heinrichmeyer@fernuni-hagen.de
#
# $FreeBSD$
#

PORTNAME=	FSViewer.app
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	x11-fm windowmaker
MASTER_SITES=	http://www.bayernline.de/~gscholz/linux/fsviewer/
DISTNAME=	FSViewer.app-${PORTVERSION}

MAINTAINER=	Fritz.Heinrichmeyer@fernuni-hagen.de
COMMENT=	X11 file manager using WINGS library. Dockable in WindowMaker

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/FSViewer
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/FSViewer

.include <bsd.port.mk>
