# $FreeBSD$

PORTNAME=	openhantek
DISTVERSION=	3.2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital Software Oscilloscope (DSO) software for Hantek oscilloscopes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		cmake compiler:c++11-lang gl localbase qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	OpenHantek
GH_PROJECT=	OpenHantek6022 # there's also the openhantek project which OpenHantek6022 is a fork of
USE_QT=		core gui opengl printsupport widgets buildtools_build linguist_build qmake_build
USE_GL=		gl glu

OPTIONS_DEFINE=		HANTEK_AC

HANTEK_AC_DESC=		Allow AC input with a modified hardware
HANTEK_AC_CMAKE_ON=	-DHANTEK_AC=1

PLIST_FILES=	bin/OpenHantek \
		etc/devd/openhantek.conf \
		share/applications/OpenHantek.desktop \
		share/icons/hicolor/48x48/apps/OpenHantek.png \
		share/icons/hicolor/scalable/apps/OpenHantek.svg

.include <bsd.port.mk>
