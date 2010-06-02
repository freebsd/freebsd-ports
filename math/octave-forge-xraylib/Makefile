# New ports collection makefile for:	octave-forge-xraylib
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-xraylib
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
GNU_CONFIGURE=	yes

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash

post-patch:
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/xraylib/src/*.sh
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/xraylib/src/Makefile
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/xraylib/bin/xraylib
	@${REINPLACE_CMD} s+/bin/bash+/usr/local/bin/bash+g ${WRKSRC}/src/xraylib/*.sh

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
