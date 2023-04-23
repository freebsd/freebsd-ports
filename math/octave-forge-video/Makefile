PORTNAME=	octave-forge-video
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		octave pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	HOME=${WRKSRC}

.include <bsd.port.mk>
