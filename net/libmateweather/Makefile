# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmateweather
PORTVERSION=	1.8.0
CATEGORIES=	net mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk20 libxml2 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.weather.gschema.xml

.include <bsd.port.mk>
