PORTNAME=	ffmpegthumbs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications
PKGNAMEPREFIX=	kdemultimedia-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FFmpeg-based thumbnail generator for video files

LICENSE=	GPLv2

LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	completion config coreaddons i18n jobwidgets kio service widgetsaddons
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
