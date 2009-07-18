# New ports collection makefile for:	ffmpegthumbnailer
# Date created:		Mo 18 Feb 2008 06:11:13 CET
# Whom:			Dierk Sacher <dierk@blaxxtarz.de>
#
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dierk@blaxxtarz.de
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		swscale:${PORTSDIR}/multimedia/ffmpeg \
		jpeg.10:${PORTSDIR}/graphics/jpeg

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack

.include <bsd.port.mk>
