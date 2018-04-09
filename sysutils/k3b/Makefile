# $FreeBSD$

PORTNAME=	k3b
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils multimedia kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CD/DVD writing suite

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libKF5Cddb.so:audio/libkcddb \
		libcdda_paranoia.so:audio/cdparanoia \
		libdvdread.so:multimedia/libdvdread \
		libmad.so:audio/libmad \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libtag.so:audio/taglib \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	cdrecord:sysutils/cdrtools
BUILD_DEPENDS=	cdrecord:sysutils/cdrtools

USES=		cmake:outsource desktop-file-utils gettext iconv kde:5 pkgconfig \
		shared-mime-info tar:xz

USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons ecm filemetadata i18n iconthemes \
		itemviews jobwidgets kcmutils kio newstuff notifications \
		notifyconfig service solid widgetsaddons xmlgui
USE_QT5=	core dbus gui network webkit widgets xml \
		buildtools_build qmake_build

# The ffmpeg-plugin needs patching
CMAKE_ARGS=	-DK3B_BUILD_FFMPEG_DECODER_PLUGIN:BOOL=FALSE

.include <bsd.port.mk>
