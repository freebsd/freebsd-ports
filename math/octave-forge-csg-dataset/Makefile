PORTNAME=	octave-forge-csg-dataset
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	${OCTAVE_PKGNAME}

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
