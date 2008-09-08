# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-gsl
PORTVERSION=	1.0.7
CATEGORIES=     math

MAINTAINER=	stephen@math.missouri.edu
COMMENT=        Octave-forge package ${OCTAVE_PKGNAME}

LIB_DEPENDS=	gsl.12:${PORTSDIR}/math/gsl

post-patch:
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/config*

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
