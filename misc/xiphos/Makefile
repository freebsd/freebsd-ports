# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.6
PORTREVISION=	6
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bible interface utilizing the sword framework

LICENSE=	GPLv2

BROKEN_FreeBSD_12=	fails to compile: /usr/include/c++/v1/type_traits:1116:29: recursive template instantiation exceeded maximum depth of 25

BUILD_DEPENDS=	${RUN_DEPENDS} \
		docbook2html:textproc/docbook-utils \
		gnome-doc-tool:textproc/gnome-doc-utils \
		nspr>=4.8:devel/nspr
LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libdbus-glib-1.so:devel/dbus-glib  \
		libsword.so:misc/sword
RUN_DEPENDS=	yelp:x11/yelp

USES=		gettext pkgconfig waf
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gtkhtml4 intlhack gtk30 gconf2 libgsf \
		gtk-update-icon-cache

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/icon-theme.cache

.include <bsd.port.mk>
