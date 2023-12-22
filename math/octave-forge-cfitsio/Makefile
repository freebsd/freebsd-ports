PORTNAME=	octave-forge-cfitsio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libcfitsio.so:astro/cfitsio

USES=		autoreconf octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-cfitsio

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
