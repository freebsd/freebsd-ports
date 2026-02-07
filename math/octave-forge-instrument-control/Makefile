PORTNAME=	octave-forge-instrument-control
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.10.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	instrument-control

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-librpc

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

.include <bsd.port.mk>
