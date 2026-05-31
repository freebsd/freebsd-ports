PORTNAME=	octave-forge-octave_boost
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LIB_DEPENDS+=	libboost_atomic.so:devel/boost-libs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	CNOCTAVE
GH_PROJECT=	octave_boost

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

pre-configure:
	${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
