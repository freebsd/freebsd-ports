# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamermm/Makefile,v 1.6 2009/09/26 13:42:00 marcus Exp $

PORTNAME=	gstreamermm
PORTVERSION=	0.10.10.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	C++ wrapper library for the multimedia library GStreamer

LICENSE=	LGPL21

USES=		compiler:c++11-lang gmake libtool pathfix pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GSTREAMER=	theora vorbis cdparanoia gio pango
USE_GNOME=	gnomeprefix gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PLIST_SUB=	GST_VERSION="${GST_VERSION}"

post-patch:
# Fix the build with clang
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "conftest\\.$$objext"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
