# New ports collection makefile for:	octave-forge-fenv
# Date created:		6 June 2010
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-fenv
PORTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTAVE_PKGNAME}/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTAVE_PKGNAME}

.include <bsd.port.post.mk>
