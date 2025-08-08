PORTNAME=	octave-forge-onsas
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		this software is incompatible with octave pkg

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	ONSAS
GH_PROJECT=	ONSAS.m

OCTAVE_SRC=		${GH_ACCOUNT}-${DISTVERSION}

NO_ARCH	=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
