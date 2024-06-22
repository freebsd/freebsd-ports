PORTNAME=	gnome-online-accounts
PORTVERSION=	3.48.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interface provider to access the user's online accounts
WWW=		https://wiki.gnome.org/Projects/GnomeOnlineAccounts/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libjavascriptcoregtk-4.1.so:www/webkit2-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		librest-1.0.so:net/librest1 \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk3

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool \
		localbase meson pathfix pkgconfig tar:xz vala:build

USE_GNOME=	cairo glib20 gtk30 introspection libxml2 libxslt:build

USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_GROUP=		PROVIDERS
OPTIONS_GROUP_PROVIDERS=	EXCHANGE FEDORA GOOGLE IMAP_SMTP KERBEROS LASTFM MEDIA_SERVER OWNCLOUD WINDOWS_LIVE
OPTIONS_DEFINE=		GOABACKEND GTK_DOC INSPECTOR INTROSPECTION MAN VAPI
OPTIONS_DEFAULT=	EXCHANGE GOABACKEND GOOGLE IMAP_SMTP INTROSPECTION LASTFM OWNCLOUD VAPI WINDOWS_LIVE

KERBEROS_LIB_DEPENDS=	libgck-1.so:security/gcr \
			libkrb5.so:security/krb5
FEDORA_LIB_DEPENDS=	libgck-1.so:security/gcr \
			libkrb5.so:security/krb5

EXCHANGE_MESON_TRUE=	exchange
FEDORA_MESON_TRUE=	fedora
GOABACKEND_MESON_TRUE=	goabackend
GOOGLE_MESON_TRUE=	google
GTK_DOC_MESON_TRUE=	gtk_doc
IMAP_SMTP_MESON_TRUE=	imap_smtp
INSPECTOR_MESON_TRUE=	inspector
INTROSPECTION_MESON_TRUE=	introspection
KERBEROS_MESON_TRUE=	kerberos
LASTFM_MESON_TRUE=	lastfm
MAN_MESON_TRUE=	man
MEDIA_SERVER_MESON_TRUE=	media_server
OWNCLOUD_MESON_TRUE=	owncloud
VAPI_MESON_TRUE=	vapi
WINDOWS_LIVE_MESON_TRUE=	windows_live

EXCHANGE_DESC=	Enable Microsoft Exchange provider
FEDORA_DESC=	Enable Fedora Account System provider
GOABACKEND_DESC=	Enable goabackend library
GOOGLE_DESC=	Enable Google provider
GTK_DOC_DESC=	Use gtk_doc to build documentation
IMAP_SMTP_DESC=	Enable IMAP/SMTP provider
INSPECTOR_DESC=	Enable a WebKitWebInspector for the embedded web view
INTROSPECTION_DESC=	Enable GObject Introspection (depends on GObject)
KERBEROS_DESC=	Enable kerberos provider
LASTFM_DESC=	Enable Last.fm provider
MAN_DESC=	Enable man pages
MEDIA_SERVER_DESC=	Enable Media Server provider
OWNCLOUD_DESC=	Enable ownCloud provider
VAPI_DESC=	Build Vala binding
WINDOWS_LIVE_DESC=	Enable Windows Live provider

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOABACKEND}
GLIB_SCHEMAS+= org.gnome.online-accounts.gschema.xml
.endif

.if ${PORT_OPTIONS:MFEDORA} || ${PORT_OPTIONS:MKERBEROS}
PLIST_SUB+= FEDORA_OR_KERBEROS=""
.else
PLIST_SUB+= FEDORA_OR_KERBEROS="@comment "
.endif

.include <bsd.port.mk>
