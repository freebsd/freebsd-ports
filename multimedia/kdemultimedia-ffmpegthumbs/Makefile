PORTNAME=	ffmpegthumbs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications
PKGNAMEPREFIX=	kdemultimedia-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FFmpeg-based thumbnail generator for video files
WWW=		https://www.kde.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons i18n jobwidgets kio service solid \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
