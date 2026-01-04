PORTNAME=	octave-forge-netcdf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.19
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libnetcdf.so:science/netcdf

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-netcdf
GNU_CONFIGURE=	yes

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
