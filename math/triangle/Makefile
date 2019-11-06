# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	triangle
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	NL/voronoi
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Two-Dimensional Quality Mesh Generator and Delaunay Triangulator

NO_CDROM=	No commercial use without prior arrangement with the author

USES=		zip xorg
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_FILES=	bin/${PORTNAME} bin/showme \
		include/${PORTNAME}.h \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.${PORTVERSION}

post-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -DTRILIBRARY -shared -fPIC -Wl,-soname,lib${PORTNAME}.so.${PORTVERSION} -o lib${PORTNAME}.so.${PORTVERSION} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKSRC}/showme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s lib${PORTNAME}.so.${PORTVERSION} lib${PORTNAME}.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${PORTVERSION}

do-test:
	@cd ${INSTALL_WRKSRC} && ./${PORTNAME} -p A.poly && ./showme A.1.poly

.include <bsd.port.mk>
