PORTNAME=	haruna
DISTVERSION=	1.8.1
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
RUN_DEPENDS=	kio-extras>0:devel/kio-extras

USES=		cmake desktop-file-utils gettext-tools gl kde:6 pkgconfig \
		qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	breeze colorscheme config coreaddons crash \
		filemetadata i18n iconthemes kio kirigami2 \
		windowsystem \
		ecm:build
USE_QT=		5compat base declarative shadertools
USE_XORG=	x11

OPTIONS_DEFINE=		YTDLP

YTDLP_DESC=		Install yt-dlp to play videos from youtube
YTDLP_RUN_DEPENDS=	yt-dlp:www/yt-dlp

.include <bsd.port.mk>
