# New ports collection makefile for:	octave-forge-bim
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-bim
PORTVERSION=	1.0.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

RUN_DEPENDS+=	${TARBALLS_DIR}/fpl.tar.gz:${PORTSDIR}/math/octave-forge-fpl
RUN_DEPENDS+=	${TARBALLS_DIR}/msh.tar.gz:${PORTSDIR}/math/octave-forge-msh

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
do-build:
	@${DO_NADA}

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

.include <bsd.port.post.mk>
