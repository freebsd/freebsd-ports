# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libextractor
PORTVERSION=	1.3
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for keyword extraction

LICENSE=	GPLv3+

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		iconv gettext libtool makeinfo pathfix pkgconfig python
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk-version=2 \
		--with-ltdl=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	$$(pkg-config --cflags gtk+-2.0) \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

INFO=		libextractor

OPTIONS_DEFINE=		EXIV2 FFMPEG FLAC GIF GSF GSTREAMER MPEG2 MP4 \
			RPM SMF TIDY VORBIS
OPTIONS_DEFAULT=	EXIV2 FFMPEG FLAC GIF GSF GSTREAMER MPEG2 MP4 \
			RPM SMF TIDY VORBIS
OPTIONS_SUB=		yes

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CONFIGURE_ENV=	EXIV2_H="<exiv2/image.hpp>"
EXIV2_CONFIGURE_ENV_OFF=	EXIV2_H=""
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ENV_OFF= ac_cv_lib_FLAC_FLAC__stream_decoder_init_stream=no
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	ffmpeg
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_ENV_OFF=	ac_cv_lib_gif_DGifOpen=no
GSF_DESC=		GSF (OLE2 (MS office) support)
GSF_USE=		gnome=libgsf
GSF_CONFIGURE_ENV_OFF=	ac_cv_lib_gsf_1_gsf_init=no
GSTREAMER_USE=		gstreamer1=yes
GSTREAMER_CONFIGURE_WITH=	gstreamer
MPEG2_LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2
MPEG2_CONFIGURE_ENV_OFF=	ac_cv_lib_mpeg2_mpeg2_init=no
MP4_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
MP4_CONFIGURE_ENV_OFF=	ac_cv_lib_mp4v2_MP4ReadProvider=no
RPM_DESC=		RPM support
RPM_LIB_DEPENDS=	librpm.so:archivers/rpm4
RPM_CONFIGURE_ENV=	ac_cv_lib_rpm_rpmReadPackageFile=yes
RPM_CONFIGURE_ENV_OFF=	ac_cv_lib_rpm_rpmReadPackageFile=no
SMF_DESC=		Standard MIDI file support via LibSMF
SMF_LIB_DEPENDS=	libsmf.so:audio/libsmf
SMF_CONFIGURE_ENV_OFF=	ac_cv_lib_smf_smf_load_from_memory=no
TIDY_LIB_DEPENDS=	libtidy.so:www/tidy-lib
TIDY_CONFIGURE_ENV=	TIDY_H="<tidy/tidy.h>"
TIDY_CONFIGURE_ENV_OFF=	TIDY_H=""
VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_CONFIGURE_ENV_OFF=	ac_cv_lib_vorbisfile_ov_open_callbacks=no

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++|| ; \
		 s|-lc_r|-pthread| ; \
		 s|<exiv2/image.hpp>|$${EXIV2_H}| ; \
		 s|<tidy/tidy.h>|$${TIDY_H}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/src/plugins/Makefile.in

.include <bsd.port.mk>
