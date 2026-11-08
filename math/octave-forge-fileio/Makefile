PORTNAME=	octave-forge-fileio
DISTVERSION=	1.2.4
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/io.tar.gz:math/octave-forge-io

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	reprostat
GH_PROJECT=	fileio

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
