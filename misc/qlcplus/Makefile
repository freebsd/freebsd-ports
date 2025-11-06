PORTNAME=	qlcplus
DISTVERSIONPREFIX=	QLC+_
DISTVERSION=	5.0.1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Q Light Controller Plus (QLC+)
WWW=		https://github.com/mcallegari/qlcplus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libftdi1.so:devel/libftdi1 \
		libola.so:misc/ola \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd

USES=		desktop-file-utils gl pkgconfig qmake qt:5 shared-mime-info shebangfix
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	mcallegari
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		core gui multimedia network script serialport testlib websockets widgets \
		buildtools:build linguisttools:build

SHEBANG_FILES=	translate.sh

BINARY_ALIAS=	g++=${CXX}

post-patch:
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|; s|/etc|${PREFIX}/etc|' ${WRKSRC}/variables.pri

.include <bsd.port.mk>
