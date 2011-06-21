# New ports collection makefile for:	octave-forge-octclip
# Date created:		13 Janurary 2011
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-octclip
PORTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=	${WRKDIR}/${OCTAVE_PKGNAME}/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-extract:
	${REINPLACE_CMD} s/CC/MKOCTFILE/ ${WRKSRC}/Makefile

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTAVE_PKGNAME}

.include <bsd.port.post.mk>
