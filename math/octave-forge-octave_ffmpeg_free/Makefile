PORTNAME=	octave-forge-octave_ffmpeg_free
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LIB_DEPENDS+=	libavutil.so:multimedia/ffmpeg

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	CNOCTAVE
GH_PROJECT=	octave_ffmpeg_free

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

pre-configure:
	${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
