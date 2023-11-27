PORTNAME=	haruna
DISTVERSION=	0.12.3
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player
WWW=		https://invent.kde.org/multimedia/haruna

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libmpv.so:multimedia/mpv
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		yt-dlp:www/yt-dlp

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth breeze codecs completion config configwidgets coreaddons \
		doctools filemetadata i18n iconthemes kirigami2 jobwidgets \
		kio service solid widgetsaddons windowsystem \
		ecm:build doctools:build \
		breeze-icons:run qqc2-desktop-style:run
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
