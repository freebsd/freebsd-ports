PORTNAME=	hepmc3
DISTVERSION=	3.3.0
CATEGORIES=	science
MASTER_SITES=	https://hepmc.web.cern.ch/hepmc/releases/
DISTNAME=	HepMC3-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Event record for High Energy Physics Monte Carlo generators/simulation
WWW=		https://hepmc.web.cern.ch/hepmc/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	HEPMC3_ENABLE_PYTHON HEPMC3_BUILD_STATIC_LIBS HEPMC3_ENABLE_ROOTIO HEPMC3_INSTALL_EXAMPLES
CMAKE_TESTING_ON=	HEPMC3_ENABLE_TEST

.include <bsd.port.mk>
