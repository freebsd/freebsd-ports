# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	triangle
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	NL/voronoi
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Two-Dimensional Quality Mesh Generator and Delaunay Triangulator

NO_CDROM=	No commercial use without prior arrangement with the author

USES=		zip
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_FILES=	bin/${PORTNAME} bin/showme \
		include/${PORTNAME}.h \
		lib/lib${PORTNAME}.so

post-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -o lib${PORTNAME}.so ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKSRC}/showme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

do-test: build
	@cd ${INSTALL_WRKSRC} && ./${PORTNAME} -p A.poly && ./showme A.1.poly

.include <bsd.port.mk>
