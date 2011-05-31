# New ports collection makefile for:	octave-forge-miscellaneous
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-miscellaneous
PORTVERSION=	1.0.11
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"

MAKE_ENV+=	MKOCTFILE=mkoctfile

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

.include <bsd.port.post.mk>
