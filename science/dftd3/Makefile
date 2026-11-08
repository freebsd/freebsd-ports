PORTNAME=	dftd3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0-3
DISTVERSIONSUFFIX=	-g8e5463e
PORTREVISION=	1
CATEGORIES=	science # quantum-chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	S. Grimme's dispersion correction for DFT, Hartree-Fock methods
WWW=		https://www.chemie.uni-bonn.de/grimme/de/software/dft-d3

LICENSE=	GPLv1+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake fortran

USE_GITHUB=	yes
GH_ACCOUNT=	loriab

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility

PLIST_FILES=	bin/dftd3

.include <bsd.port.mk>
