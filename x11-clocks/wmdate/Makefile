# New ports collection makefile for:	wmdate
# Version required:	0.7
# Date created:		1 February 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.2 1999/04/11 12:44:52 jseger Exp $
#

DISTNAME=	wmdate-0.7
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://wit401310.student.utwente.nl/apps/apps/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${PREFIX}/include/dockapp.h:${PORTSDIR}/devel/libdockapp

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmdate
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmdate
	@${ECHO} "===>   README installed in ${PREFIX}/share/doc/wmdate"
.endif

.include <bsd.port.mk>
