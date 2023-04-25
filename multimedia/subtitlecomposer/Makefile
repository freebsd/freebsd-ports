PORTNAME=	subtitlecomposer
DISTVERSION=	0.7.1.20230404
PORTREVISION=	2
CATEGORIES=	multimedia kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced FFmpeg-based subtitle editor
WWW=		https://subtitlecomposer.kde.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang cmake desktop-file-utils gettext \
		kde:5 openal pkgconfig qt:5 shared-mime-info tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons jobwidgets i18n itemviews kio kross \
		parts service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		buildtools:build qmake:build testlib:build \
		concurrent core dbus declarative gui network script widgets xml
USE_XORG=	x11

KDE_INVENT=	838063e2d6a90a1219b8880ffa71570c9c9c31c0 multimedia subtitlecomposer

# Requires PocketSphinx-5prealpha
SPHINX_DESC=	Speech recognition via PocketSphinx
SPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_PocketSphinx=ON

post-patch:
	${RM} ${WRKSRC}/cmake/FindICU.cmake

.include <bsd.port.mk>
