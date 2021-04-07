PORTNAME=	mcxtrace-comps
DISTVERSION=	1.2
CATEGORIES=	science
MASTER_SITES=	http://downloads.mcxtrace.org/mcxtrace-${DISTVERSION}/unix/mcxtrace-${DISTVERSION}-src/
DISTNAME=	mcxtrace-comps-${DISTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Component Library for the McXtrace X-ray tracing package

LICENSE=	LGPL21+

RUN_DEPENDS=	${LOCALBASE}/mcxtrace/${DISTVERSION}/bin/mcxtrace:science/mcxtrace

USES=		cmake
# Apparently cmake does not generate an install/strip target if nothing
# is supposed to be stripped, so override the cmake-default install
# target of install/strip by resetting STRIP
STRIP=		#none
CMAKE_ARGS=	"-Denable_mcxtrace=1"
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
