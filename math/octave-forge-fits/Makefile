# New ports collection makefile for:	octave-forge-fits
# Date created:		13 Janurary 2011
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-fits
PORTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=	${WRKDIR}/${OCTAVE_PKGNAME}/src

LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTAVE_PKGNAME}

.include <bsd.port.post.mk>
