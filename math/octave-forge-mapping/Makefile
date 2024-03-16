PORTNAME=	octave-forge-mapping
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/io.tar.gz:math/octave-forge-io \
		${OCTAVE_TARBALLS_DIR}/geometry.tar.gz:math/octave-forge-geometry

USES=		octave

GNU_CONFIGURE=	yes

ALL_TARGET=	# nada

.include <bsd.port.mk>
