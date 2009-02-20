# New ports collection makefile for:	gstreamermm
# Date created:		2008-02-23
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamermm/Makefile,v 1.2 2008/03/15 21:09:37 ahze Exp $

PORTNAME=	gstreamermm
PORTVERSION=	0.10.1
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	C++ wrapper library for the multimedia library GStreamer

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GSTREAMER=	yes
USE_GNOME=	pkgconfig gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs --disable-examples
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/gstreamerbase `pkg-config --cflags gtkmm-2.4 glibmm-2.4 libxml++-2.6 gstreamer-${GST_VERSION}` -I${WRKSRC}/gstreamer"
USE_LDCONFIG=	yes
PLIST_SUB=	GST_VERSION="${GST_VERSION}"

.include <bsd.port.mk>
