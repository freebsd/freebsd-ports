# New ports collection makefile for:   kino
# Date created:        10 April 2004
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kino
PORTVERSION=	0.7.5
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://kino.schirmacher.de/filemanager/download/42/	\
		http://perso.enst.fr/~beyssac/mirrors/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		Magick.8:${PORTSDIR}/graphics/ImageMagick	\
		samplerate.1:${PORTSDIR}/audio/libsamplerate

OPTIONS=	QUICKTIME "With Quicktime support" off

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui libxml2
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS=-"I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAN1=	kino.1

.include <bsd.port.pre.mk>

.if defined(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--with-quicktime
.endif

.include <bsd.port.post.mk>
