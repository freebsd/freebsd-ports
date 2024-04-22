PORTNAME=	octave-forge-secs1d
PORTVERSION=	0.0.9
PORTREVISION=	25
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/bim.tar.gz:math/octave-forge-bim

USES=		octave

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${OCTAVE_SRC}

.include <bsd.port.mk>
