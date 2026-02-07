PORTNAME=	octave-forge-csg-toolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/io.tar.gz:math/octave-forge-io

USES=		compiler octave
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	${OCTAVE_PKGNAME}

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
