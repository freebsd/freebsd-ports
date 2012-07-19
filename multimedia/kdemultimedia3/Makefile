# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Multimedia
# Date created:				Saturday 7 December 2002
# Whom:					Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	7
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia utilities for the KDE integrated X11 desktop

CONFLICTS=	juk-1*

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		FLAC:${PORTSDIR}/audio/flac \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		ogg:${PORTSDIR}/audio/libogg \
		tag:${PORTSDIR}/audio/taglib \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

MAKE_ENV=	${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--with-vorbis="${LOCALBASE}" --disable-xinetest
CONFIGURE_ENV+=	AKODE_CONFIG=${LOCALBASE}/bin/akode-config
USE_LDCONFIG=	yes
DO_NOT_COMPILE+=akode juk mpeglib mpeglib_artsplug xine_artsplugin

OPTIONS_DEFINE=	AKODE MPEGLIB XINE
OPTIONS_DEFAULT=	AKODE
AKODE_DESC=	akode for audio playback
MPEGLIB_DESC=	Use mpeglib for audio playback
XINE_DESC=	support for video playback using libxine

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAKODE}
LIB_DEPENDS+=	akode:${PORTSDIR}/audio/akode
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode.so:${PORTSDIR}/audio/akode
PLIST_SUB+= AKODE=""
.else
DO_NOT_COMPILE+=akode_artsplugin
PLIST_SUB+= AKODE="@comment "
.endif

.if ${PORT_OPTIONS:MXINE}
RUN_DEPENDS+=	${LOCALBASE}/lib/libarts_xine.la:${PORTSDIR}/multimedia/xine_artsplugin
.endif

.if ${PORT_OPTIONS:MMPEGLIB}
RUN_DEPENDS+=	mpeglibartsplay:${PORTSDIR}/audio/mpeglib_artsplug
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

pre-configure:
	${REINPLACE_CMD} -e "s,applications-merged,kde-applications-merged,g" \
		${WRKSRC}/kappfinder-data/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
