# New ports collection makefile for:	workplace
# Version required:			1.0a1
# Date created:				7 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	workplace-1.0.a1
PKGNAME=	workplace-1.0a1
CATEGORIES=	x11
MASTER_SITES=	http://www2.osk.3web.ne.jp/~hideki70/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11/gtk

GNU_CONFIGURE=	yes
USE_X11=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/workplace ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/include/X11/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
	@ ${MKDIR} ${PREFIX}/share/doc/workplace
.for file in AUTHORS INSTALL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/workplace
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/workplace
	@ ${INSTALL_DATA} ${WRKSRC}/WPPref ${PREFIX}/share/examples/workplace/WPPref.sample
	@ ${INSTALL_DATA} ${WRKSRC}/WPSuffix ${PREFIX}/share/examples/workplace/WPSuffix.sample

.include <bsd.port.mk>
