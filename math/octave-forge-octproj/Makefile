# New ports collection makefile for:	octave-forge-octproj
# Date created:		5 June 2010
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-octproj
PORTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTAVE_PKGNAME}/src

LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTAVE_PKGNAME}

.include <bsd.port.post.mk>
