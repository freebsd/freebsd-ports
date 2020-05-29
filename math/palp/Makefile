# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	palp
PORTVERSION=	2.11
CATEGORIES=	math
MASTER_SITES=	http://hep.itp.tuwien.ac.at/~kreuzer/CY/palp/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for Analyzing Lattice Polytopes

LICENSE=	GPLv3

MAKEFILE=	GNUmakefile

DIMENSIONS=	4 5 6 11
RESDIR=		${WRKDIR}/result
PROGS=		class cws mori nef poly

pre-build:
	${MV} ${WRKSRC}/Global.h ${WRKSRC}/Global.h-template
	${MKDIR} ${RESDIR}

do-build:
.for dim in ${DIMENSIONS}
	${SED} "s/^#define[^a-zA-Z]*POLY_Dmax.*/#define POLY_Dmax ${dim}/"	\
		${WRKSRC}/Global.h-template > ${WRKSRC}/Global.h
	(cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET})
. for prog in ${PROGS}
	${CP} ${WRKSRC}/${prog}.x ${RESDIR}/${prog}-${dim}d.x
. endfor
	(cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} cleanall)
.endfor

do-install:
.for dim in ${DIMENSIONS}
. for prog in ${PROGS}
	${INSTALL_PROGRAM} ${RESDIR}/${prog}-${dim}d.x ${STAGEDIR}${PREFIX}/bin
. endfor
.endfor
	# symlinks for the default dimension
.for prog in ${PROGS}
	(cd ${STAGEDIR}${PREFIX}/bin &&	\
		${LN} -sf ${prog}-6d.x ${STAGEDIR}${PREFIX}/bin/${prog}.x)
.endfor

test:
	# To be completed
	${ECHO_CMD} "24 3 3 4 4 10" | ${RESDIR}/class-6d.x -f -po zbin

.include <bsd.port.mk>
