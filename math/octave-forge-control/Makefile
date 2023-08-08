PORTNAME=	octave-forge-control
DISTVERSIONPREFIX=	control-
DISTVERSION=	3.6.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	pkg-control

OCTAVE_SRC=	${GH_PROJECT}-control-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
