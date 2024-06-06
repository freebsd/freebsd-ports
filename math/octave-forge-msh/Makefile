PORTNAME=	octave-forge-msh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/splines.tar.gz:math/octave-forge-splines \
		gmsh:cad/gmsh

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	carlodefalco
GH_PROJECT=	msh

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
