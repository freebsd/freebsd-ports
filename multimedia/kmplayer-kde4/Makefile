# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://www.xs4all.nl/%7Ejjvrieze/
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.r/-rc/}
DISTVERSION=	0.8.4-rc4a

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE frontend to mplayer

#EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure
EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-configure

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--with-x=${X11BASE} --disable-debug

OPTIONS=	GSTREAMER "Enable support for video playback using gstreamer" off \
		XINE "Enable support for video playback using libxine" off 

WANT_GNOME=	gstreamerplugins

###
## Lib Detection
###
# gstreamer
.if exists(${X11BASE}/lib/libgstplay-0.8.so)
WITH_GSTREAMER=yes
.endif
# xine
.if exists(${X11BASE}/lib/libxine.so)
WITH_XINE=yes
.endif

post-patch:
# remove -pedantic where possible to fix build errors on -CURRENT
# remove optimizations
	@${REINPLACE_CMD} -e \
		's|-O2||; s|-pedantic ||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# do not try to roll our own mimetypes
	@${REINPLACE_CMD} -E -e \
		's|^(SUBDIRS.*)mimetypes|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

###
## Internal Detection
###
# gstreamer
.if ${HAVE_GNOME:Mgstreamerplugins}
WITH_GSTREAMER=yes
.endif

###
## Support Activation
###
# gstreamer
.if defined(WITH_GSTREAMER)
USE_GNOME+=	gstreamerplugins

PLIST_FILES+=	bin/kgstplayer
.else
CONFIGURE_ARGS+=	--without-gstreamer
.endif
# xine
.if defined(WITH_XINE)
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine

PLIST_FILES+=	bin/kxineplayer
.endif

# GCC < 3.1
.if ${OSVERSION} < 500035
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src::kmplayerplaylist.cpp
.endif

.include <bsd.port.post.mk>
