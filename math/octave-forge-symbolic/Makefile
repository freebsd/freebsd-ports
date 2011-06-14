# New ports collection makefile for:	octave-forge-symbolic
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-symbolic
PORTVERSION=	1.0.9
PORTREVISION=	4
CATEGORIES=	math

PATCH_SITES=	http://www.baycom.org/~tom/octave/
PATCHFILES=	octave-symbolic.patch

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

GNU_CONFIGURE=	yes

LIB_DEPENDS+=	ginac:${PORTSDIR}/math/GiNaC

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
