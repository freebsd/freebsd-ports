# New ports collection makefile for:	wmdate
# Date created:		1 February 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmdate
PORTVERSION=	0.7
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/apps/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/

MAINTAINER=	jim@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/dockapp.h:${PORTSDIR}/x11-wm/libdockapp

USE_IMAKE=	yes
USE_XPM=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmdate
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmdate
	@${ECHO} "===>   README installed in ${PREFIX}/share/doc/wmdate"
.endif

.include <bsd.port.mk>
