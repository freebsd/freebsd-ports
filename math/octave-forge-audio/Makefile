PORTNAME=	octave-forge-audio
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
DISTVERSION=	2.0.8
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS+=	librtmidi.so:audio/rtmidi

USES=		compiler:c++11-lang octave pkgconfig autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-audio

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
