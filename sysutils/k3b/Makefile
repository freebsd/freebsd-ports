# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	k3b
PORTVERSION=	1.0.5
PORTREVISION=	17
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	SF

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A CD/DVD recording GUI for KDE

RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cdrecord:${PORTSDIR}/sysutils/cdrtools
LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		samplerate:${PORTSDIR}/audio/libsamplerate

PORTSCOUT=	ignore:1

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-k3bsetup=no \
			--without-resmgr \
			--without-hal \
			--without-musepack \
			--without-musicbrainz
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_KDELIBS_VER=	3

OPTIONS_DEFINE=	ALSA DVDPLUSRW EMOVIX FFMPEG FLAC LAME LIBDVDREAD NORMALIZE SOX TRANSCODE VCDIMAGER
OPTIONS_DEFAULT=	DVDPLUSRW FLAC LAME LIBDVDREAD
DVDPLUSRW_DESC=	Add DVD+RW Tools (for DVD+/-R(W) burning)
EMOVIX_DESC=	Add eMovix (to burn bootable video CD)
LIBDVDREAD_DESC=	Use libdvdread (for video dvd ripping)
NORMALIZE_DESC=	Add Normalize (adjust audio to a std. level)
SOX_DESC=	Add SoX (more audio encoding formats)
TRANSCODE_DESC=	Add Transcode (for DVD ripping)
VCDIMAGER_DESC=	Add VCDImager (for Video CD burning)

pre-configure:
	${RM} ${WRKSRC}/admin/cvs.sh
	${TOUCH} ${WRKSRC}/admin/cvs.sh

post-install:
	@${CAT} ${PKGMESSAGE}
	@sleep 5

showinfo:
	more ${PKGMESSAGE}

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900044
EXTRA_PATCHES=		${FILESDIR}/extra-patch-libk3bdevice-k3bscsicommandbsd.cpp
.endif

PKGMESSAGE=	${PKGDIR}/pkg-message-7

.if ${PORT_OPTIONS:MFLAC}
PLIST_SUB+=	FLAC=""
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
PLIST_SUB+=	FLAC="@comment "
CONFIGURE_ARGS+=	--without-flac
.endif

.if ${PORT_OPTIONS:MLAME}
PLIST_SUB+=	LAME=""
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
.else
PLIST_SUB+=	LAME="@comment "
CONFIGURE_ARGS+=	--without-lame
.endif

.if ${PORT_OPTIONS:MFFMPEG}
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
.else
PLIST_SUB+=	FFMPEG="@comment "
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MLIBDVDREAD}
PLIST_SUB+=	LIBDVDREAD=""
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
.else
PLIST_SUB+=	LIBDVDREAD="@comment "
CONFIGURE_ARGS+=	--without-libdvdread
.endif

.if ${PORT_OPTIONS:MDVDPLUSRW}
RUN_DEPENDS+=	dvd+rw-format:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.if ${PORT_OPTIONS:MTRANSCODE}
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

.if ${PORT_OPTIONS:MEMOVIX}
RUN_DEPENDS+=	mkmovixiso:${PORTSDIR}/multimedia/emovix
.endif

.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if ${PORT_OPTIONS:MVCDIMAGER}
RUN_DEPENDS+=	vcdxrip:${PORTSDIR}/multimedia/vcdimager
.endif

.if ${PORT_OPTIONS:MALSA}
PLIST_SUB+=	ALSA=""
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=	--with-alsa
.else
PLIST_SUB+=	ALSA="@comment "
CONFIGURE_ARGS+=	--without-alsa
.endif

.include <bsd.port.mk>
