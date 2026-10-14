PORTNAME=	octave-forge-parts
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/drafting.tar.gz:math/octave-forge-drafting

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	${OCTAVE_PKGNAME}

OCTAVE_SRC=		${GH_PROJECT}-release-${DISTVERSION}

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
