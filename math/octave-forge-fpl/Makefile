# New ports collection makefile for:	octave-forge-fpl
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-fpl
PORTVERSION=	0.1.3
CATEGORIES=     math

MAINTAINER=	stephen@math.missouri.edu
COMMENT=        Octave-forge package ${OCTAVE_PKGNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ${ARCH} != "sparc64"
RUN_DEPENDS+=	dx:${PORTSDIR}/graphics/opendx
.endif

.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
