PORTNAME=	octave-forge-fxp
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	ahmedshahein
GH_PROJECT=	pkg-fxp

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
