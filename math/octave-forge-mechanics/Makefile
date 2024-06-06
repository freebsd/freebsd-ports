PORTNAME=	octave-forge-mechanics
PORTVERSION=	1.3.1
PORTREVISION=	24
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		does not build with octave=8

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/general.tar.gz:math/octave-forge-general \
		${OCTAVE_TARBALLS_DIR}/geometry.tar.gz:math/octave-forge-geometry \
		${OCTAVE_TARBALLS_DIR}/linear-algebra.tar.gz:math/octave-forge-linear-algebra

USES=		octave

OCTAVE_SRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTAVE_SRC}/inst/molecularDynamics/src

.include <bsd.port.mk>
