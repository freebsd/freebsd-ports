# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-xraylib
PORTVERSION=	1.0.8
PORTREVISION=	11
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		does not build with octave-4.0.0

GNU_CONFIGURE=	yes

BUILD_DEPENDS+=	bash:shells/bash

post-patch:
	@${REINPLACE_CMD} s+/bin/bash+${LOCALBASE}/bin/bash+g ${WRKSRC}/src/xraylib/src/*.sh
	@${REINPLACE_CMD} s+/bin/bash+${LOCALBASE}/bin/bash+g ${WRKSRC}/src/xraylib/src/Makefile
	@${REINPLACE_CMD} s+/bin/bash+${LOCALBASE}/bin/bash+g ${WRKSRC}/src/xraylib/bin/xraylib
	@${REINPLACE_CMD} s+/bin/bash+${LOCALBASE}/bin/bash+g ${WRKSRC}/src/xraylib/*.sh

.include "${.CURDIR}/../../Mk/bsd.octave.mk"
.include <bsd.port.mk>
