PORTNAME=	octave-forge-nan
PORTVERSION=	3.7.2
CATEGORIES=	math
MASTER_SITES=	https://pub.ista.ac.at/~schloegl/matlab/NaN/
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		gmake octave

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	octave

.include <bsd.port.mk>
