# New ports collection makefile for:	octave-forge-optim
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-optim
PORTVERSION=	1.0.12
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

.include <bsd.port.post.mk>
