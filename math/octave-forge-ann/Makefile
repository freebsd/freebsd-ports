# New ports collection makefile for:	octave-forge-ann
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-ann
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

RUN_DEPENDS+=	swig:${PORTSDIR}/devel/swig13

BROKEN=		Does not compile with octave-3.2.2
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
