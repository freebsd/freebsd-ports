# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/epiphany3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	epiphany
PORTVERSION=	3.6.1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
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

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_PYTHON=	yes
USE_SQLITE=	3
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_GNOME=	gnomedesktop3 gnomedocutils gnomeprefix intlhack libxml2
USE_XORG=	ice x11 sm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-introspection \
		--with-distributor-name="FreeBSD GNOME Project"
#		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

OPTIONS_DEFINE=	AVAHI SPELLCHECK
OPTIONS_DEFAULT=AVAHI SPELLCHECK
SPELLCHECK_DESC=Enable spell checking by default

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--enable-compile-warnings=no

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-gobject.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-zeroconf
.endif

.if ${PORT_OPTIONS:MSPELLCHECK}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-embed_ephy-embed-prefs.c
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
