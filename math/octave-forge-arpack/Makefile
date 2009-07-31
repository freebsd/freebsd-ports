# New ports collection makefile for:	octave-forge-arpack
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-arpack
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

NO_CDROM=	arpack is licensed for non-commercial use only

LIB_DEPENDS+=	arpack:${PORTSDIR}/math/arpack

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
