# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Multimedia
# Date created:				Saturday 7 December 2002
# Whom:					Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia utilities for the KDE integrated X11 desktop

CONFLICTS=	juk-*

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		FLAC:${PORTSDIR}/audio/flac \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		mad:${PORTSDIR}/audio/libmad \
		musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		ogg:${PORTSDIR}/audio/libogg \
		speex:${PORTSDIR}/audio/speex \
		tag:${PORTSDIR}/audio/taglib \
		tunepimp:${PORTSDIR}/audio/libtunepimp \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
_NO_KDE_FINAL=	yes
_NO_KDE_CLOSURE=yes

MAKE_ENV=	${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--with-vorbis="${LOCALBASE}" --disable-xinetest
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
DO_NOT_COMPILE+=mpeglib mpeglib_artsplug xine_artsplugin

OPTIONS=	MPEGLIB "Use mpeglib for audio playback" on \
		XINE "Enable support for video playback using libxine" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_XINE)
RUN_DEPENDS=	${LOCALBASE}/lib/libarts_xine.la:${PORTSDIR}/multimedia/xine_artsplugin
.endif

.if !defined(WITHOUT_MPEGLIB)
RUN_DEPENDS+=		mpeglibartsplay:${PORTSDIR}/audio/mpeglib_artsplug
.elseif defined(WITHOUT_MPEGLIB)
# Use the KFile plugins. Those can't do streaming, but work better with
# some buggy(?) sound drivers in -STABLE.
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

pre-configure:
	${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
