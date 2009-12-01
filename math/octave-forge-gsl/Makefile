# New ports collection makefile for:	octave-forge-gsl
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-gsl
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LIB_DEPENDS=	gsl.14:${PORTSDIR}/math/gsl

post-patch:
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/config*

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
