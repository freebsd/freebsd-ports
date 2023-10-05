PORTNAME=	subtitlecomposer
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced FFmpeg-based subtitle editor
WWW=		https://subtitlecomposer.kde.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang cmake desktop-file-utils gettext \
		kde:5 openal pkgconfig qt:5 shared-mime-info ssl tar:xz xorg
USE_KDE=	bookmarks codecs completion config configwidgets \
		coreaddons jobwidgets i18n itemviews kio \
		service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		buildtools:build qmake:build testlib:build \
		concurrent core dbus declarative gui network widgets xml
USE_XORG=	x11

# Requires PocketSphinx-5prealpha
SPHINX_DESC=	Speech recognition via PocketSphinx
SPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_PocketSphinx=ON

post-patch:
	${RM} ${WRKSRC}/cmake/FindICU.cmake

.include <bsd.port.mk>
