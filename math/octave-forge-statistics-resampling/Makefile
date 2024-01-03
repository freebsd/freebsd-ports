PORTNAME=	octave-forge-statistics-resampling
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	statistics-resampling

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

ALL_TARGET=	make

CONFLICTS_INSTALL=	octave-forge-statistics-bootstrap

.include <bsd.port.mk>
