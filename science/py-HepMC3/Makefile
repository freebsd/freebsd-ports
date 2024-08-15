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

BROKEN_i386=	compilation fails, static_assert(sizeof(IntType) <= sizeof(ssize_t), "Implicit narrowing is not permitted."), reported to the ML hepmc-dev@cern.ch on 2024-06-24
BROKEN_powerpc=	compilation fails, static_assert(sizeof(IntType) <= sizeof(ssize_t), "Implicit narrowing is not permitted."), reported to the ML hepmc-dev@cern.ch on 2024-06-24

LIB_DEPENDS=	libHepMC3.so:science/hepmc3

USES=		cmake compiler:c++11-lang python
USE_PYTHON=	flavors

WRKSRC_SUBDIR=	python

CMAKE_ON=	USE_INSTALLED_HEPMC3
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	HEPMC3_ENABLE_TEST
CMAKE_TESTING_ON=	HEPMC3_ENABLE_TEST

.include <bsd.port.mk>
