PORTNAME=	openhantek
DISTVERSION=	3.4.0-2026-10-16
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital Software Oscilloscope (DSO) software for Hantek oscilloscopes
WWW=		https://github.com/OpenHantek/OpenHantek6022

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		cmake desktop-file-utils gl localbase qt:6
USE_QT=		base tools:build
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	OpenHantek
GH_PROJECT=	OpenHantek6022 # there's also the openhantek project which OpenHantek6022 is a fork of
GH_TAGNAME=	bb36066 # has Qt6 compatibility fixes

OPTIONS_DEFINE=		HANTEK_AC

HANTEK_AC_DESC=		Allow AC input with a modified hardware
HANTEK_AC_CMAKE_ON=	-DHANTEK_AC=1

PLIST_FILES=	bin/OpenHantek \
		etc/devd/openhantek.conf \
		share/applications/org.openhantek.OpenHantek.desktop \
		share/icons/hicolor/48x48/apps/OpenHantek.png \
		share/icons/hicolor/scalable/apps/OpenHantek.svg

PORTSCOUT=	limit:^.*[1-9]\. # prevent words like 'unstable'

.include <bsd.port.mk>
