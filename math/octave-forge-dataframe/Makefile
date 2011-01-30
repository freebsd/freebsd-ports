# New ports collection makefile for:	octave-forge-dataframe
# Date created:		26 August 2010
# Whom:			Stephen Montgomery-Smith <stephen@missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-dataframe
PORTVERSION=	0.8.2
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
do-build:
	@${DO_NADA}

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

.include <bsd.port.post.mk>
