PORTNAME=	palp
PORTVERSION=	2.21
CATEGORIES=	math
MASTER_SITES=	http://hep.itp.tuwien.ac.at/~kreuzer/CY/palp/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for Analyzing Lattice Polytopes
WWW=		http://hep.itp.tuwien.ac.at/~kreuzer/CY/CYpalp.html

LICENSE=	GPLv3

USES=		gmake
MAKEFILE=	GNUmakefile
ALL_TARGET=	all-dims
TEST_TARGET=	check

DIMENSIONS=	4 5 6 11
RESDIR=		${WRKDIR}/result
PROGS=		class cws mori nef poly

do-install:
.for prog in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${prog}.x ${STAGEDIR}${PREFIX}/bin
. for dim in ${DIMENSIONS}
	${INSTALL_PROGRAM} ${WRKSRC}/${prog}-${dim}d.x ${STAGEDIR}${PREFIX}/bin
. endfor
.endfor

.include <bsd.port.mk>
