PORTNAME=	octave-forge-octave-pool
DISTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/fileio.tar.gz:math/octave-forge-fileio

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	reprostat
GH_PROJECT=	octave-pool

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
