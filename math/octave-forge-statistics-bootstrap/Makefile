PORTNAME=	octave-forge-statistics-bootstrap
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.8
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/statistics.tar.gz:math/octave-forge-statistics

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	statistics-bootstrap

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

ALL_TARGET=	make

.include <bsd.port.mk>
