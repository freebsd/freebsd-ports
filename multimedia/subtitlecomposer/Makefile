PORTNAME=	subtitlecomposer
DISTVERSION=	0.8.2
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}

PATCH_SITES=	https://invent.kde.org/multimedia/subtitlecomposer/-/commit/
PATCHFILES+=	1e11d53565ab6df3ba8329072e7b4b12f9f88d72.patch:-p1 # Fix configure with Qt 6.10

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced FFmpeg-based subtitle editor
WWW=		https://subtitlecomposer.kde.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++17-lang cmake desktop-file-utils gettext \
		kde:6 openal pkgconfig qt:6 shared-mime-info ssl tar:xz
USE_KDE=	codecs config configwidgets coreaddons i18n \
		kio sonnet textwidgets widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		5compat base declarative \
		tools:build
USE_XORG=	x11

# Requires PocketSphinx-5prealpha
SPHINX_DESC=	Speech recognition via PocketSphinx
SPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_PocketSphinx=ON

post-patch:
	${RM} ${WRKSRC}/cmake/FindICU.cmake

.include <bsd.port.mk>
