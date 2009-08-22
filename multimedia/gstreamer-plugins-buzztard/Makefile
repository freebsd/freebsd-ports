# New ports collection makefile for:	gstreamer-plugins-buzztard
# Date created:		2007-06-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buzztard
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20gstreamer%20extensions/${PORTVERSION}
PKGNAMEPREFIX=	gstreamer-plugins-
DISTNAME=	gst-${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Buzztard gstreamer plugins

LIB_DEPENDS=	fluidsynth.2:${PORTSDIR}/audio/fluidsynth

USE_AUTOTOOLS=	libtool:22
USE_GSTREAMER=	yes
USE_GNOME=	gnomehack ltverhack
USE_LDCONFIG=	yes
PLIST_SUB=	GST_VERSION="${GST_VERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
