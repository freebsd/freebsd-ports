PORTNAME=	haruna
DISTVERSION=	1.7.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE video player
WWW=		https://apps.kde.org/haruna/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libkdsingleapplication-qt6.so:devel/kdsingleapplication \
		libavcodec.so:multimedia/ffmpeg \
		libmpv.so:multimedia/mpv \
		libMpvQt.so:multimedia/mpvqt
RUN_DEPENDS=	kio-extras>0:devel/kio-extras \
		yt-dlp:www/yt-dlp

USES=		cmake desktop-file-utils gettext-tools gl kde:6 pkgconfig \
		qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	breeze colorscheme completion config coreaddons crash \
		filemetadata i18n iconthemes jobwidgets kio kirigami2 \
		service widgetsaddons windowsystem \
		ecm:build
USE_QT=		5compat base declarative
USE_XORG=	x11

.include <bsd.port.mk>
