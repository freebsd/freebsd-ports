PORTNAME=	octave-forge-general
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.1.5
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

USES=		octave pkgconfig autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-general

GNU_CONFIGURE=	yes

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

.include <bsd.port.mk>
