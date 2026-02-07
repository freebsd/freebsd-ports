PORTNAME=	octave-forge-bim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.8
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/fpl.tar.gz:math/octave-forge-fpl \
		${OCTAVE_TARBALLS_DIR}/msh.tar.gz:math/octave-forge-msh

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	carlodefalco
GH_PROJECT=	bim

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
