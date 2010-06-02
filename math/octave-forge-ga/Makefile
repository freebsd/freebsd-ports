# New ports collection makefile for:	octave-forge-ga
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-ga
PORTVERSION=	0.9.7
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
GNU_CONFIGURE=	yes

RUN_DEPENDS+=	${TARBALLS_DIR}/communications.tar.gz:${PORTSDIR}/math/octave-forge-communications

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
