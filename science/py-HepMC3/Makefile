PORTNAME=	HepMC3
DISTVERSION=	3.3.0
CATEGORIES=	science
MASTER_SITES=	http://hepmc.web.cern.ch/hepmc/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Event record for High Energy Physics Monte Carlo generators/simulation
WWW=		https://hepmc.web.cern.ch/hepmc/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libHepMC3.so:science/hepmc3

USES=		cmake compiler:c++11-lang python
USE_PYTHON=	flavors

WRKSRC_SUBDIR=	python

CMAKE_ON=	USE_INSTALLED_HEPMC3
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	HEPMC3_ENABLE_TEST
CMAKE_TESTING_ON=	HEPMC3_ENABLE_TEST

.include <bsd.port.mk>
