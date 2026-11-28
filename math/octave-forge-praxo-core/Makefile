PORTNAME=	octave-forge-praxo-core
DISTVERSIONPREFIX=	octave/v
DISTVERSION=	0.9.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		octave python:build
USE_GITHUB=	yes
GH_ACCOUNT=	axisvela
GH_PROJECT=	praxo-core

OCTAVE_SRC=	${GH_PROJECT}-octave-v${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_ARCH=	yes

do-build:
	${PYTHON_CMD} ${WRKSRC}/language/octave/build_octave_package.py
	${CP} ${WRKSRC}/language/octave/build/octave/${OCTAVE_PKGNAME}-${DISTVERSION}.tar.gz ${WRKDIR}/${OCTAVE_PKGNAME}-${DISTVERSION}.tar.gz

pre-install:
	@${NADA}

.include <bsd.port.mk>
