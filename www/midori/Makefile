# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midori
PORTVERSION=	0.5.6
CATEGORIES=	www xfce
MASTER_SITES=	http://www.midori-browser.org/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}_all_
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LICENSE=	LGPL21

BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DUSE_GRANITE:BOOL=OFF \
	-DUSE_GCR:BOOL=OFF

WRKSRC=	${WRKDIR}/${DISTNAME:C/([a-z]*)_([0-9\.]*)(_all_)/\1-\2/}
USE_BZIP2=	yes
USE_GNOME=	glib20 intltool libxml2
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USES=		desktop-file-utils pkgconfig cmake gettext

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=	DOCS ZEITGEIST
OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2
ZEITGEIST_DESC=	User logs activities

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
USE_GNOME+=	gtk20
CMAKE_ARGS+=	-DUSE_GTK3:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGTK3}
LIB_DEPENDS+=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
USE_GNOME+=	gtk30
CMAKE_ARGS+=	-DUSE_GTK3:BOOL=ON

# Support the new WebKit2 API (>= 1.11.91)
.if exists(${LOCALBASE}/libdata/pkgconfig/webkit2gtk-3.0.pc)
CMAKE_ARGS+=	-DHALF_BRO_INCOM_WEBKIT2:BOOL=ON
.else
CMAKE_ARGS+=	-DHALF_BRO_INCOM_WEBKIT2:BOOL=OFF
.endif
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
CMAKE_ARGS+=	-DUSE_APIDOCS:BOOL=ON
PLIST_SUB+=	APIDOCS=""
.else
CMAKE_ARGS+=	-DUSE_APIDOCS:BOOL=OFF
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MZEITGEIST}
LIB_DEPENDS+=	libzeitgeist-1.0.so:${PORTSDIR}/sysutils/libzeitgeist
CMAKE_ARGS+=	-DUSE_ZEITGEIST:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_ZEITGEIST:BOOL=OFF
.endif

post-patch:
# Avoid errors with CMake
.for dir in config extensions
	@cd ${WRKSRC} && ${RM} ${dir}/*.orig
.endfor

.include <bsd.port.mk>
