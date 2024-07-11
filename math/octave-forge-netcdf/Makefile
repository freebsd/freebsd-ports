PORTNAME=	octave-forge-netcdf
PORTVERSION=	1.0.17
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libnetcdf.so:science/netcdf

USES=		octave

GNU_CONFIGURE=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
