# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.6
PORTREVISION=	7
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bible interface utilizing the sword framework

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		docbook2html:textproc/docbook-utils \
		gnome-doc-tool:textproc/gnome-doc-utils \
		nspr>=4.8:devel/nspr
LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libdbus-glib-1.so:devel/dbus-glib  \
		libsword.so:misc/sword \
		libdbus-1.so:devel/dbus \
		libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant
RUN_DEPENDS=	yelp:x11/yelp

USES=		gettext gnome pkgconfig waf
USE_GNOME=	cairo gtkhtml4 intlhack gtk30 gconf2 libgsf \
		gtk-update-icon-cache

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CXXFLAGS+=	-ftemplate-depth=1024

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/icon-theme.cache

.include <bsd.port.mk>
