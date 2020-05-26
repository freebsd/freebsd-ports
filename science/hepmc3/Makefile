# $FreeBSD$

PORTNAME=	hepmc3
DISTVERSION=	3.2.1
CATEGORIES=	science
MASTER_SITES=	http://hepmc.web.cern.ch/hepmc/releases/
DISTNAME=	HepMC3-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Event record for High Energy Physics Monte Carlo generators/simulation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	HEPMC3_ENABLE_PYTHON HEPMC3_BUILD_STATIC_LIBS HEPMC3_ENABLE_ROOTIO

.include <bsd.port.mk>
