# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-engine
PORTVERSION=	1.0.9
PORTREVISION=	19
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		does not build with octave version >= 4.4.0
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-12-19

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	HOME=${WRKSRC}

.include "${.CURDIR}/../../Mk/bsd.octave.mk"
.include <bsd.port.mk>
