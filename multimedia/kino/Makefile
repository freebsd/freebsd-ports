# New ports collection makefile for:   kino
# Date created:        10 April 2004
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kino
PORTVERSION=	0.7.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}	\
		http://kino.schirmacher.de/filemanager/download/17/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		glade-2.0:${PORTSDIR}/devel/libglade2	\
		gnomeui-2.600:${PORTSDIR}/x11-toolkits/libgnomeui	\
		ICE.6:${PORTSDIR}/x11/libICE			\
		intl.6:${PORTSDIR}/devel/gettext		\
		Magick.6:${PORTSDIR}/graphics/ImageMagick	\
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS=-"I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
MAN1=	kino.1

.include <bsd.port.mk>
