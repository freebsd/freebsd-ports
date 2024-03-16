PORTNAME=	octave-forge-fits
PORTVERSION=	1.0.7
PORTREVISION=	21
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		does not build with octave version >= 9.1.0

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

USES=		octave

NO_ARCH=	yes

.include <bsd.port.mk>
