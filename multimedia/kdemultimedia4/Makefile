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

RUN_DEPENDS+=	xanim:${PORTSDIR}/graphics/xanim
LIB_DEPENDS+=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	esound
GNU_CONFIGURE=	yes

MAKE_ENV=	${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--without-lame \
			--with-vorbis=${LOCALBASE} \
			--enable-audio=oss,esd

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_MIDI) || defined(WITHOUT_KMIDI)
DO_NOT_COMPILE+=	kmidi
.else
PLIST_APPEND+=	plist.midi
.if ${MACHINE_ARCH} == "alpha"
USE_REINPLACE=	yes
post-patch::
	${REINPLACE_CMD} -e "s|-ffast-math||g" ${WRKSRC}/kmidi/Makefile.in
.endif # ${MACHINE_ARCH} == "alpha"
.endif # defined(WITHOUT_MIDI)

DO_NOT_COMPILE+=	xine-artsplugin

.if exists(${X11BASE}/bin/xine-config)
WITH_XINE=	yes
.endif # exists(${LOCALBASE}/bin/xine-config)

.if defined(WITH_XINE)
post-patch::
	${ECHO_MSG} Cannot use libxine at this time. The library was
	${ECHO_MSG} broken at the time this package was prepared.
.endif # defined(WITH_XINE)

#.if defined(WITH_XINE)
#PLIST_APPEND+=	plist.xine
#LIB_DEPENDS+=	xine.2:${PORTSDIR}/graphics/libxine
#BUILD_DEPENDS+=	xine-config:${PORTSDIR}/graphics/libxine
#.endif # defined(WITH_XINE)

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
