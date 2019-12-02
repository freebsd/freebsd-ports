# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-matgeom
PORTVERSION=	1.2.1
#DISTVERSIONSUFFIX=	.octave
CATEGORIES=	math
DISTFILES=	${DISTNAME}.octave${EXTRACT_SUFX}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-extract:
	@${MV} ${WRKDIR}/${OCTSRC}.octave ${WRKDIR}/${OCTSRC}
	@${REINPLACE_CMD} -E 's/\.octave//' ${WRKDIR}/${OCTSRC}/DESCRIPTION

do-build:
	@${DO_NADA}

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
