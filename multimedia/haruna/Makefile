PORTNAME=	haruna
DISTVERSION=	0.7.3
PORTREVISION=	1
MASTER_SITES=	KDE/stable/${PORTNAME}/
CATEGORIES=	multimedia kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player

LIB_DEPENDS=	libmpv.so:multimedia/mpv
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		yt-dlp:www/yt-dlp

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		filemetadata i18n iconthemes kirigami2 itemviews jobwidgets kio \
		service solid widgetsaddons windowsystem xmlgui \
		ecm_build doctools_build \
		breeze_run breeze-icons_run qqc2-desktop-style_run
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
