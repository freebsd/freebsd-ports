# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-msh
PORTVERSION=	1.0.10
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src
GNU_CONFIGURE=	yes

RUN_DEPENDS+=	${TARBALLS_DIR}/splines.tar.gz:math/octave-forge-splines
RUN_DEPENDS+=	gmsh:cad/gmsh

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-patch:
	${REINPLACE_CMD} 's/ $$(LDFLAGS)//' ${WRKSRC}/Makefile.in

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
