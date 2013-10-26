# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-oct2mat
PORTVERSION=	1.0.7
PORTREVISION=	8
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

GNU_CONFIGURE=	yes

RUN_DEPENDS+=	${TARBALLS_DIR}/io.tar.gz:${PORTSDIR}/math/octave-forge-io

NO_STAGE=	yes
.include "${.CURDIR}/../../Mk/bsd.octave.mk"
.include <bsd.port.mk>
