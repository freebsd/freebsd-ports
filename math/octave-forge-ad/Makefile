# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-ad
PORTVERSION=	1.0.6
PORTREVISION=	12
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	HOME=${WRKSRC}
USES=		dos2unix

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

BROKEN=		doesn't build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-11-01

.include <bsd.port.mk>
