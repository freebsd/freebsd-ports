# New ports collection makefile for:	octave-forge-nan
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-nan
PORTVERSION=	2.4.4
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/NaN/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"

ALL_TARGET=	octave

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz NaN

.include <bsd.port.post.mk>
