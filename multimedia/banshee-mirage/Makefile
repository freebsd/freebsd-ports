# New ports collection makefile for:	banshee-mirage
# Date created:		2009-03-22
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	mirage
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://hop.at/mirage/download/
PKGNAMEPREFIX=	banshee-

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Automatic Playlist Generation Extension for Banshee

BUILD_DEPENDS=	banshee-1:${PORTSDIR}/multimedia/banshee
RUN_DEPENDS=	banshee-1:${PORTSDIR}/multimedia/banshee
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

BROKEN=		does not build

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GNOME=	intltool gnomehack

.include <bsd.port.mk>
