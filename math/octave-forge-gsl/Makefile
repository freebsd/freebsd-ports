# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-gsl
PORTVERSION=	1.0.8
PORTREVISION=	14
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} s+/bin/bash+${LOCALBASE}/bin/bash+g ${WRKSRC}/src/config*

.include "${.CURDIR}/../../Mk/bsd.octave.mk"
.include <bsd.port.mk>
