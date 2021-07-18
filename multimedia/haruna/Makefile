PORTNAME=	haruna
DISTVERSION=	0.6.3
CATEGORIES=	multimedia kde

PATCH_SITES=	https://invent.kde.org/berner/haruna/-/commit/
PATCHFILES=	500d2af4c4b9d62e749f3949cf0f0919634680ed.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player

LIB_DEPENDS=	libmpv.so:multimedia/mpv
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		youtube-dl:www/youtube_dl

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		filemetadata i18n iconthemes kirigami2 itemviews jobwidgets kio \
		service solid widgetsaddons windowsystem xmlgui \
		ecm_build doctools_build \
		breeze_run breeze-icons_run qqc2-desktop-style_run
KDE_INVENT=	588e747c6a683d1467300dfcc2f3a992b0c07a42
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
