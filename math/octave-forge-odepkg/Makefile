# New ports collection makefile for:	octave-forge-odepkg
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-odepkg
PORTVERSION=	0.6.10
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

.include <bsd.port.post.mk>
