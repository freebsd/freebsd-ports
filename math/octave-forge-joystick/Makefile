PORTNAME=	octave-forge-joystick
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.4
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS+	cmake:devel/cmake # Required by configure.

LIB_DEPENDS+=	libSDL2.so:devel/sdl20

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-joystick

GNU_CONFIGURE=	yes

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
