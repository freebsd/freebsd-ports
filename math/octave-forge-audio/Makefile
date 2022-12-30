PORTNAME=	octave-forge-audio
PORTVERSION=	2.0.5
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS+=	librtmidi.so:audio/rtmidi

USES=		compiler:c++11-lang octave pkgconfig

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
