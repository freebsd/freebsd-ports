# New ports collection makefile for:  triangle
# Date created:               16 Octobre 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	triangle
PORTVERSION=	1.5
CATEGORIES=	math
MASTER_SITES=	http://cm.bell-labs.com/netlib/voronoi/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Two-Dimensional Quality Mesh Generator and Delaunay Triangulator

NO_CDROM=	Triangle must not be sold for profit

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_XLIB=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/triangle bin/showme

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:S|^bin|${WRKSRC}|} ${PREFIX}/bin

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${INSTALL_WRKSRC} && ./triangle -p A.poly && ./showme A.1.poly)
.endif

.include <bsd.port.mk>
