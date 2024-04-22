PORTNAME=	octave-forge-data-smoothing
PORTVERSION=	1.3.0
PORTREVISION=	24
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/optim.tar.gz:math/octave-forge-optim

USES=		octave

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${OCTAVE_PKGNAME}

.include <bsd.port.mk>
