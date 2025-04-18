PORTNAME=	haruna
DISTVERSION=	1.4.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player
WWW=		https://invent.kde.org/multimedia/haruna

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libMpvQt.so:multimedia/mpvqt
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		yt-dlp:www/yt-dlp

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	breeze colorscheme completion config coreaddons crash \
		filemetadata i18n iconthemes kirigami2 kio windowsystem \
		ecm:build
USE_QT=		5compat base declarative
USE_XORG=	x11

.include <bsd.port.mk>
