PORTNAME=	octave-forge-fileio
DISTVERSION=	1.2.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	reprostat
GH_PROJECT=	fileio

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

WRKSRC=		${WRKDIR}/${OCTAVE_SRC}	# Required so that patch will apply.

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
