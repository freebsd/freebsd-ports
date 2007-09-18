# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
PORTVERSION=	0.9.4a
PORTEPOCH=	2
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/ \
		http://freebsd.ricin.com/ports/distfiles/
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.r/-rc/}

MAINTAINER=	danny@ricin.com
COMMENT=	KDE frontend to mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

OPTIONS=	GSTREAMER	"Enable gstreamer playback support" off \
		XINE		"Enable libxine playback support" off

WANT_GSTREAMER=	yes

post-patch:
# do not try to roll our own mimetypes
	@${REINPLACE_CMD} -E -e \
		's|^(SUBDIRS.*)mimetypes|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes
PLIST_FILES+=	bin/kgstplayer
.else
CONFIGURE_ARGS+=	--without-gstreamer
.endif
.if defined(WITH_XINE)
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
PLIST_FILES+=	bin/kxineplayer
.else
CONFIGURE_ARGS+=	--without-xine
.endif

.include <bsd.port.post.mk>
