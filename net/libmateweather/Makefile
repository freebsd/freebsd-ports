PORTNAME=	libmateweather
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.1
PORTREVISION=	1
CATEGORIES=	net mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information
WWW=		https://mate-desktop.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		autoreconf gettext gmake gnome libtool localbase pathfix pkgconfig

PORTSCOUT=	limitw:1,even
USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
USE_GNOME=	cairo gtk30 intltool libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.weather.gschema.xml

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtk-doc>=0:textproc/gtk-doc
DOCS_CONFIGURE_ON=	--enable-gtk-doc --with-html-dir=${PREFIX}/share/doc

.include <bsd.port.mk>
