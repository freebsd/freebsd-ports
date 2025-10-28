PORTNAME=	octave-forge-llms
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.1.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/datatypes.tar.gz:math/octave-forge-datatypes

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	octave-llms

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

.include <bsd.port.mk>
