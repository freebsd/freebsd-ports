PORTNAME=	plantri
DISTVERSION=	5.2
CATEGORIES=	math
MASTER_SITES=	http://users.cecs.anu.edu.au/~bdm/plantri/
DISTNAME=	${PORTNAME}${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plantri and fullgen are programs to generate planar graph

MAKEFILE=	makefile
MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/plantri \
		bin/fullgen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plantri ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fullgen ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
