# New ports collection makefile for:	octave-forge-signal
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-signal
PORTVERSION=	1.0.10
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
GNU_CONFIGURE=	yes

RUN_DEPENDS+=	${TARBALLS_DIR}/optim.tar.gz:${PORTSDIR}/math/octave-forge-optim
RUN_DEPENDS+=	${TARBALLS_DIR}/specfun.tar.gz:${PORTSDIR}/math/octave-forge-specfun

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
