# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Multimedia
# Date created:				Saturday 7 December 2002
# Whom:					Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia utilities for the KDE integrated X11 desktop

CONFLICTS=	juk-*

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		FLAC:${PORTSDIR}/audio/flac \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		mp3lame:${PORTSDIR}/audio/lame \
		ogg:${PORTSDIR}/audio/libogg \
		tag:${PORTSDIR}/audio/taglib \
		vorbis.3:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	trm:${PORTSDIR}/audio/trm
RUN_DEPENDS=	trm:${PORTSDIR}/audio/trm

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAKE_ENV=	${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--with-vorbis="${LOCALBASE}"
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

OPTIONS=	XINE "Enable support for video playback, using libxine" off \
		MPEGLIB "Use mpeglib for audio playback" on

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/xine-config)
.	if !defined(WITH_XINE)
XINE_OVERRIDE=	yes
WITH_XINE=	yes
.	endif
.endif

.if defined(WITH_XINE)
PLIST_APPEND+=	plist.xine
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
BUILD_DEPENDS+=	xine-config:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--with-xine-prefix=${X11BASE}
.else
DO_NOT_COMPILE+=        xine_artsplugin
CONFIGURE_ARGS+=        --disable-xinetest
.endif

.if defined(WITH_MPEGLIB)
PLIST_APPEND+=	plist.mpeglib
.else
PLIST_APPEND+=	plist.no-mpeglib
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

pre-everything::
.if defined(XINE_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "*    libxine is installed but WITH_XINE is not set!    *"
	@${ECHO_MSG} "*       WITH_XINE has been enabled automatically.      *"
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG}
.endif

pre-configure:
.if !defined(WITH_MPEGLIB)
	${REINPLACE_CMD} -e \
	'/FreeBSD/,/;$$/s/kde_mpeglib_compiles=yes/kde_mpeglib_compiles=no/g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e '/union semun/,/;$$/s/.*//g' \
		${WRKSRC}/oggvorbis_artsplugin/oggPlayObject_impl.h
.endif
	${REINPLACE_CMD} -e 's/-lc_r/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} -e '/^XINE_CFLAGS/s/-D_THREAD_SAFE//g' \
			-e 's/-pthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/xine_artsplugin/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
