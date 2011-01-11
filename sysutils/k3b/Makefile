# New ports collection makefile for:    k3b
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	k3b
PORTVERSION=	1.0.5
PORTREVISION=	10
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CD/DVD recording GUI for KDE

RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao
LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		samplerate:${PORTSDIR}/audio/libsamplerate

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-k3bsetup=no \
			--without-resmgr \
			--without-hal \
			--without-musepack
USE_GMAKE=	yes
USE_CDRTOOLS=	yes
USE_LDCONFIG=	yes
USE_KDELIBS_VER=	3

OPTIONS=	ALSA "Add audio/alsa-lib support" Off \
		DVDPLUSRW "Add DVD+RW Tools (for DVD+/-R(W) burning)" On \
		EMOVIX "Add eMovix (to burn bootable video CD)" Off \
		FFMPEG "Add multimedia/ffmpeg decoder (for wma files)" Off \
		FLAC "Add audio/flac decoder" On \
		LAME "Add audio/lame encoder (for mp3 files)" On \
		LIBDVDREAD "Use libdvdread (for video dvd ripping)" On \
		MUSICBRAINZ "Use audio/libmusicbrainz music meta database" Off \
		NORMALIZE "Add Normalize (adjust audio to a std. level)" Off \
		SOX "Add SoX (more audio encoding formats)" Off \
		TRANSCODE "Add Transcode (for DVD ripping)" Off \
		VCDIMAGER "Add VCDImager (for Video CD burning)" Off

pre-configure:
	${RM} ${WRKSRC}/admin/cvs.sh
	${TOUCH} ${WRKSRC}/admin/cvs.sh

post-install:
	@${CAT} ${PKGMESSAGE}
	@sleep 5

showinfo:
	more ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
PKGMESSAGE=	${PKGDIR}/pkg-message-7
.endif

.if defined(WITH_FLAC)
PLIST_SUB+=	FLAC=""
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
PLIST_SUB+=	FLAC="@comment "
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_LAME)
PLIST_SUB+=	LAME=""
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
.else
PLIST_SUB+=	LAME="@comment "
CONFIGURE_ARGS+=	--without-lame
.endif

.if defined(WITH_FFMPEG)
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
.else
PLIST_SUB+=	FFMPEG="@comment "
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_MUSICBRAINZ)
PLIST_SUB+=	MUSICBRAINZ=""
LIB_DEPENDS+=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz
.else
PLIST_SUB+=	MUSICBRAINZ="@comment "
CONFIGURE_ARGS+=	--without-musicbrainz
.endif

.if defined(WITH_LIBDVDREAD)
PLIST_SUB+=	LIBDVDREAD=""
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
.else
PLIST_SUB+=	LIBDVDREAD="@comment "
CONFIGURE_ARGS+=	--without-libdvdread
.endif

.if !defined (WITHOUT_DVDPLUSRW)
RUN_DEPENDS+=	dvd+rw-format:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.if defined (WITH_TRANSCODE)
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

.if defined (WITH_EMOVIX)
RUN_DEPENDS+=	mkmovixiso:${PORTSDIR}/multimedia/emovix
.endif

.if defined (WITH_NORMALIZE)
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if defined (WITH_SOX)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if defined (WITH_VCDIMAGER)
RUN_DEPENDS+=	vcdxrip:${PORTSDIR}/multimedia/vcdimager
.endif

.if defined (WITH_ALSA)
PLIST_SUB+=	ALSA=""
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=	--with-alsa
.else
PLIST_SUB+=	ALSA="@comment "
CONFIGURE_ARGS+=	--without-alsa
.endif

.include <bsd.port.post.mk>
