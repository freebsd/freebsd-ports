# New ports collection makefile for:	workplace
# Version required:			1.0a3
# Date created:				7 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1998/08/07 22:33:12 asami Exp $
#

DISTNAME=	workplace-1.0.a3
PKGNAME=	workplace-1.0a3
CATEGORIES=	x11-fm
MASTER_SITES=	http://www2.osk.3web.ne.jp/~hideki70/src/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11-toolkits/gtk

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

pre-configure:
	@ ${RM} ${WRKSRC}/config.cache

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/workplace ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/include/X11/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
	@ ${MKDIR} ${PREFIX}/share/doc/workplace
.for file in AUTHORS INSTALL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/workplace
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/workplace
	@ ${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/workplace

.include <bsd.port.mk>
