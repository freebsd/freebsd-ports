# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	triangle
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	NL/voronoi
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Two-Dimensional Quality Mesh Generator and Delaunay Triangulator

NO_CDROM=	No commercial use without prior arrangement with the author

NO_WRKSUBDIR=	yes
USES=		zip
USE_XORG=	x11
MAKEFILE=	makefile

PLIST_FILES=	bin/triangle bin/showme

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:S|^bin|${WRKSRC}|} ${STAGEDIR}${PREFIX}/bin

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${INSTALL_WRKSRC} && ./triangle -p A.poly && ./showme A.1.poly)
.endif

.include <bsd.port.mk>
