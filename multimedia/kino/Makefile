# New ports collection makefile for:   kino
# Date created:        10 April 2004
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kino
PORTVERSION=	0.7.1
CATEGORIES=	multimedia
MASTER_SITES=	http://kino.schirmacher.de/filemanager/download/31/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		Magick.6:${PORTSDIR}/graphics/ImageMagick	\
		samplerate.0:${PORTSDIR}/audio/libsamplerate

USE_GETTEXT=	yes
USE_GNOME=	libgnomeui libxml2
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS=-"I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
MAN1=	kino.1

.include <bsd.port.mk>
