PORTNAME=	octave-forge-sqlite
DISTVERSIONPREFIX=	v
PORTREVISION=	1
DISTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		autoreconf octave pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-sqlite

GNU_CONFIGURE=	yes

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
