PORTNAME=	octave-forge-financial
PORTVERSION=	0.5.3
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/io.tar.gz:math/octave-forge-io \
		${OCTAVE_TARBALLS_DIR}/statistics.tar.gz:math/octave-forge-statistics

BROKEN=		does not install with octave version >= 9.1.0

USES=		octave

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
