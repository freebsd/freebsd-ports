PORTNAME=	octave-forge-video
DISTVERSION=	2.1.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4

USES=		octave pkgconfig autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	Andy1978
GH_PROJECT=	octave-video

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/ffmpeg4/include
CONFIGURE_ENV+=	HOME=${WRKSRC} PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg4/libdata/pkgconfig"

.include <bsd.port.mk>
