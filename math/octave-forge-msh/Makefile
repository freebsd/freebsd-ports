# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-msh
PORTVERSION=	0.0.7
CATEGORIES=     math

MAINTAINER=	stephen@math.missouri.edu
COMMENT=        Octave-forge package ${OCTAVE_PKGNAME}

RUN_DEPENDS+=	${TARBALLS_DIR}/splines.tar.gz:${PORTSDIR}/math/octave-forge-splines
RUN_DEPENDS+=	gmsh:${PORTSDIR}/cad/gmsh

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
