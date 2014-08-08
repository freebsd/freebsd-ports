# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/epiphany/Makefile 19792 2014-08-08 17:19:32Z gusi $

PORTNAME=	epiphany
PORTVERSION=	3.12.1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		itstool:${PORTSDIR}/textproc/itstool \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libnss3.so:${PORTSDIR}/security/nss \
		libavahi-gobject.so:${PORTSDIR}/net/avahi-app \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

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
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

CONFIGURE_ARGS+=	--enable-compile-warnings=no

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
