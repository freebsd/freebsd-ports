# New ports collection makefile for:	wmdate
# Date created:		1 February 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmdate
PORTVERSION= 	0.7
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://wit401310.student.utwente.nl/apps/apps/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${X11BASE}/include/dockapp.h:${PORTSDIR}/x11-wm/libdockapp

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmdate
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmdate
	@${ECHO} "===>   README installed in ${PREFIX}/share/doc/wmdate"
.endif

.include <bsd.port.mk>
