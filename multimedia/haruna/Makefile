PORTNAME=	haruna
DISTVERSION=	0.11.2
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player
WWW=		https://invent.kde.org/multimedia/haruna

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libmpv.so:multimedia/mpv
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		yt-dlp:www/yt-dlp

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		doctools filemetadata i18n iconthemes kirigami2 itemviews jobwidgets \
		kio service solid widgetsaddons windowsystem xmlgui \
		ecm:build doctools:build \
		breeze:run breeze-icons:run qqc2-desktop-style:run
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
