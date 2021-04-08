PORTNAME=	subtitlecomposer
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced FFmpeg-based subtitle editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang cmake desktop-file-utils gettext \
		kde:5 openal pkgconfig qt:5 shared-mime-info tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm_build i18n \
		kio kross sonnet textwidgets widgetsaddons xmlgui \
		doctools_build
USE_QT=		buildtools_build qmake_build testlib_build core gui widgets

# Requires PocketSphinx-5prealpha
SPHINX_DESC=	Speech recognition via PocketSphinx
SPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_PocketSphinx=ON

post-patch:
	${RM} ${WRKSRC}/cmake/FindICU.cmake

.include <bsd.port.mk>
