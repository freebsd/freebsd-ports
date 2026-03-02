PORTNAME=	octave-forge-apa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		octave

LIB_DEPENDS+=	libmpfr.so:math/mpfr \

USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	pkg-apa

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
