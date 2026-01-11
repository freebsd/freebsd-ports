PORTNAME=	octave-forge-signal
DISTVERSION=	1.4.7
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/control.tar.gz:math/octave-forge-control

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-signal

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
