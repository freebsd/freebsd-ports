DISTVERSIONPREFIX=	v
PORTNAME=	octave-forge-mysql
DISTVERSION=	0.0.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave autoreconf pkgconfig mysql
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-mysql

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
