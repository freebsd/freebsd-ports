PORTNAME=	octave-forge-statistics
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.8.3
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/datatypes.tar.gz:math/octave-forge-datatypes

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	statistics

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

.include <bsd.port.mk>
