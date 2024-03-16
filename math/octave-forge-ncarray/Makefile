PORTNAME=	octave-forge-ncarray
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/netcdf.tar.gz:math/octave-forge-netcdf \
		${OCTAVE_TARBALLS_DIR}/statistics.tar.gz:math/octave-forge-statistics

USES=		octave

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
