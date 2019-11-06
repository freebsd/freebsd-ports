# Created by: Michael Elbel (me)
# $FreeBSD$

PORTNAME=	mmv
PORTVERSION=	1.01b.19
CATEGORIES=	misc
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_1.01b.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_1.01b-15.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	se@FreeBSD.org
COMMENT=	Move/Copy/Append/Link multiple files

BROKEN=		unfetchable

LICENSE=	Freeware
LICENSE_NAME=	MMV
LICENSE_FILE=	${PATCHDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CFLAGS+=	-DHAS_DIRENT
WRKSRC=		${WRKDIR}/${PORTNAME}-1.01b.orig

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mmv.1 ${STAGEDIR}${PREFIX}/man/man1/
.for i in mcp mad mln
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${i}
	${LN} -sf ${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/${i}.1
.endfor

.include <bsd.port.mk>
