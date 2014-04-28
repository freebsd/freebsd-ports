# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/www/epiphany/Makefile 19437 2014-04-01 13:07:17Z gusi $

PORTNAME=	epiphany
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		itstool:${PORTSDIR}/textproc/itstool \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libnss3.so:${PORTSDIR}/security/nss \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack libwnck3 libxml2 libxslt
USE_XORG=	ice x11 sm
INSTALLS_ICONS=	yes
USE_PYTHON=	3
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-introspection \
		--with-distributor-name="FreeBSD GNOME Project"
#		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	AVAHI
OPTIONS_DEFAULT=AVAHI

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--enable-compile-warnings=no

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-gobject.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-zeroconf
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/epiphany/3.12/web-extensions/libephywebextension.so

.include <bsd.port.mk>
