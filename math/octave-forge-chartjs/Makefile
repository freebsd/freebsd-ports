PORTNAME=	octave-forge-chartjs
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS+=	${PREFIX}/include/boost/asio.hpp:devel/boost-libs

BROKEN=		does not build with boost version 1.87

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	octave-chartjs

CXXFLAGS+=	-DCROW_USE_BOOST

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

.include <bsd.port.mk>
