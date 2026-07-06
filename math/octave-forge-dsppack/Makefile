PORTNAME=	octave-forge-dsppack
DISTVERSION=	1.1.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/signal.tar.gz:math/octave-forge-signal

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	Mihutxxl
GH_PROJECT=	dsppack

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
