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

USES=		cmake desktop-file-utils gettext iconv kde:5 pkgconfig \
		qt:5 shared-mime-info tar:xz

USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons ecm filemetadata i18n iconthemes \
		itemviews jobwidgets kcmutils kio newstuff notifications \
		notifyconfig service solid widgetsaddons xmlgui
USE_QT=		core dbus gui network webkit widgets xml \
		buildtools_build qmake_build

# The ffmpeg-plugin needs patching
CMAKE_ARGS=	-DK3B_BUILD_FFMPEG_DECODER_PLUGIN:BOOL=FALSE

OPTIONS_DEFINE=		CDRDAO DVDPLUSRW EMOVIX VCDIMAGER DOCS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

CDRDAO_DESC=		Burning: cdrdao
CDRDAO_RUN_DEPENDS=	cdrdao:sysutils/cdrdao

DVDPLUSRW_DESC=		Burning: DVD+RW tools (DVD+/-R(W))
DVDPLUSRW_RUN_DEPENDS=	dvd+rw-format:sysutils/dvd+rw-tools

EMOVIX_DESC=		Burning: eMovix (bootable video CDs)
EMOVIX_RUN_DEPENDS=	mkmovixiso:multimedia/emovix

VCDIMAGER_DESC=		Burning: VCDImager (video CDs)
VCDIMAGER_RUN_DEPENDS=	vcdxrip:multimedia/vcdimager

.include <bsd.port.mk>
