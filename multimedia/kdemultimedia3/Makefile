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

RUN_DEPENDS+=	xanim:${PORTSDIR}/multimedia/xanim
LIB_DEPENDS+=	cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		mp3lame:${PORTSDIR}/audio/lame \
		ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	esound
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAKE_ENV=	${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--with-vorbis="${LOCALBASE}" \
			--enable-audio=oss,esd

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_MIDI) || defined(WITH_KMIDI)
PLIST_APPEND+=	plist.midi
.if ${MACHINE_ARCH} == "alpha"
USE_REINPLACE=	yes
post-patch::
	${REINPLACE_CMD} -e "s|-ffast-math||g" ${WRKSRC}/kmidi/Makefile.in
.endif # ${MACHINE_ARCH} == "alpha"
.else
DO_NOT_COMPILE+=	kmidi
.endif #  defined(WITH_MIDI) || defined(WITH_KMIDI)

#.if exists(${X11BASE}/bin/xine-config)
#WITH_XINE=	yes
#.endif # exists(${LOCALBASE}/bin/xine-config)

WITHOUT_XINE=yes

.if defined(WITHOUT_XINE)
DO_NOT_COMPILE+=	xine_artsplugin
#CONFIGURE_ARGS+=	--disable-xinetest
#.elif defined(WITH_XINE)
#PLIST_APPEND+=	plist.xine
#LIB_DEPENDS+=	xine.4:${PORTSDIR}/multimedia/libxine
#BUILD_DEPENDS+=	xine-config:${PORTSDIR}/multimedia/libxine
#CONFIGURE_ARGS+=--with-xine-prefix=${X11BASE}
.endif # defined(WITHOUT_XINE)

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
