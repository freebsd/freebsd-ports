# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-spline-gcvspl
PORTVERSION=	1.0.8
PORTREVISION=	11
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

BROKEN=		does not build with octave-4.0.0

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	HOME=${WRKSRC}

NO_CDROM=	Non-commercial use only

.include "${.CURDIR}/../../Mk/bsd.octave.mk"
.include <bsd.port.mk>
