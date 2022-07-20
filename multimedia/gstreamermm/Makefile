PORTNAME=	gstreamermm
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	C++ wrapper library for the multimedia library GStreamer

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake gnome gstreamer libtool pathfix pkgconfig \
		tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gnomeprefix gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="1.0"

.include <bsd.port.mk>
