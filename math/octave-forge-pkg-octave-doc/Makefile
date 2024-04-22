PORTNAME=	octave-forge-pkg-octave-doc
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
DISTVERSION=	0.5.3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	pkg-octave-doc

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSIONPREFIX}${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
