PORTNAME=	octave-forge-ncarray
DISTVERSION=	1.0.7
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/netcdf.tar.gz:math/octave-forge-netcdf \
		${OCTAVE_TARBALLS_DIR}/statistics.tar.gz:math/octave-forge-statistics

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-ncarray

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
