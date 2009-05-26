# New ports collection makefile for:	octave-forge-engine
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-engine
PORTVERSION=	1.0.8
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} s/getline/local_getline/ ${WRKSRC}/src/engGetFull.c ${WRKSRC}/src/engif.c ${WRKSRC}/src/engif.h

.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
