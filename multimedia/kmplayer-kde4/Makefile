# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
DISTVERSION=	0.9.0-pre2
PORTEPOCH=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://www.xs4all.nl/%7Ejjvrieze/
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.r/-rc/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE frontend to mplayer

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

WANT_GSTREAMER=	yes

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
## Support Activation
###
# gstreamer
#.undef WITH_GSTREAMER
.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes

PLIST_FILES+=	bin/kgstplayer
.else
CONFIGURE_ARGS+=	--without-gstreamer
.endif
# xine
.if defined(WITH_XINE)
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine

PLIST_FILES+=	bin/kxineplayer
.endif

.include <bsd.port.post.mk>
