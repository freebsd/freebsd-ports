# $FreeBSD$

PORTNAME=	zart
PORTVERSION=	g20191124
CATEGORIES=	multimedia
MASTER_SITES=	https://gmic.eu/files/source/:gmic
DISTFILES=	gmic_${GMIC_VERSION}.tar.gz:gmic

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GMIC GUI for video streams

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgmic.so:graphics/gmic \
		libopencv_core.so:graphics/opencv-core \
		libopencv_video.so:graphics/opencv \
		libfftw3.so:math/fftw3

USES=		compiler:c++11-lang pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TAGNAME=	099554f
USE_QT=		core gui network widgets xml buildtools_build

GMIC_VERSION=	2.8.1

QMAKE_ARGS=	"GMIC_PATH=${WRKDIR}/gmic-${GMIC_VERSION}/src"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|SYS_gettid|SYS_thr_self|' ${WRKDIR}/gmic-${GMIC_VERSION}/src/gmic.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
