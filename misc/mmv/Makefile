# Created by: Michael Elbel (me)
# $FreeBSD$

PORTNAME=	mmv
PORTVERSION=	1.01b.19
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_1.01b.orig
DISTFILES=	${PORTNAME}_1.01b.orig${EXTRACT_SUFX} \
		${_debfile}

PATCH_DIST_STRIP=	-p1

MAINTAINER=	se@FreeBSD.org
COMMENT=	Move/Copy/Append/Link multiple files

LICENSE=	Freeware
LICENSE_NAME=	MMV
LICENSE_FILE=	${PATCHDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CFLAGS+=	-DHAS_DIRENT
WRKSRC=		${WRKDIR}/${PORTNAME}-1.01b.orig

_debfile=	${PORTNAME}_1.01b-19.debian.tar.xz

pre-patch:
	${TAR} -C ${WRKDIR} -xvJf ${DISTDIR}/${_debfile} debian/patches
	cd ${WRKSRC} && while read p ; do \
		${PATCH} <${WRKDIR}/debian/patches/$$p ; \
	done <${WRKDIR}/debian/patches/series

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mmv.1 ${STAGEDIR}${PREFIX}/man/man1/
.for i in mcp mad mln
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${i}
	${LN} -sf ${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/${i}.1
.endfor

.include <bsd.port.mk>
