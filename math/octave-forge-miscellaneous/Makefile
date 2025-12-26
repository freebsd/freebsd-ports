PORTNAME=	octave-forge-miscellaneous
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.3.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-miscellaneous

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
