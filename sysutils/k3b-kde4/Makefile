# New ports collection makefile for:    k3b
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	k3b
PORTVERSION=	0.12.2
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A CD/DVD recording GUI for KDE

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao
LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		dvdcss:${PORTSDIR}/multimedia/libdvdcss \
		samplerate:${PORTSDIR}/audio/libsamplerate

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-k3bsetup=no --without-resmgr --without-hal
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
USE_KDELIBS_VER=	3

OPTIONS=	SNDFILE "Add audio/libsndfile decoder (for wav files)" On \
		FLAC "Add audio/flac decoder" On \
		LAME "Add audio/lame encoder (for mp3 files)" On \
		FFMPEG "Add multimedia/ffmpeg decoder (for wma files)" Off \
		MUSICBRAINZ "Use audio/libmusicbrainz music meta database" Off \
		MPC "Add audio/libmpcdec decoder (for musepack file)" Off

pre-configure:
	${RM} ${WRKSRC}/admin/cvs.sh
	${TOUCH} ${WRKSRC}/admin/cvs.sh

post-install:
	@${CAT} ${PKGMESSAGE}
	@sleep 5

showinfo:
	more ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
PKGMESSAGE=	${PKGDIR}/pkg-message5
.endif

.if defined(WITH_SNDFILE)
PLIST_SUB+=	SNDFILE=""
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.else
PLIST_SUB+=	SNDFILE="@comment "
CONFIGURE_ARGS+=	--without-sndfile
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

.if defined(WITH_MPC)
PLIST_SUB+=	MPC=""
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/libmpcdec
.else
PLIST_SUB+=	MPC="@comment "
CONFIGURE_ARGS+=	--without-musepack
.endif

.include <bsd.port.post.mk>
