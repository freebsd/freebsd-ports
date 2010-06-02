# New ports collection makefile for:	octave-forge-zenity
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-zenity
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
GNU_CONFIGURE=	yes

RUN_DEPENDS+=	zenity:${PORTSDIR}/x11/zenity

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
