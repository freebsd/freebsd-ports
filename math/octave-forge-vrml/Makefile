# New ports collection makefile for:	octave-forge-vrml
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-vrml
PORTVERSION=	1.0.9
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous
RUN_DEPENDS+=	${TARBALLS_DIR}/struct.tar.gz:${PORTSDIR}/math/octave-forge-struct
RUN_DEPENDS+=	${TARBALLS_DIR}/statistics.tar.gz:${PORTSDIR}/math/octave-forge-statistics

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
