# New ports collection makefile for:	ffmpegthumbnailer
# Date created:		Mo 18 Feb 2008 06:11:13 CET
# Whom:			Dierk Sacher <dierk@blaxxtarz.de>
#
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	1.1.5
CATEGORIES=	multimedia graphics
MASTER_SITES=	http://ffmpegthumbnailer.googlecode.com/files/

MAINTAINER=	dierk@blaxxtarz.de
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		avcodec:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
USE_GZIP=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig

PLIST_FILES=	bin/ffmpegthumbnailer

.include <bsd.port.mk>
