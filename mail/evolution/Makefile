PORTNAME=	evolution
DISTVERSION=	3.56.2
PORTREVISION=	3
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite
WWW=		https://gitlab.gnome.org/GNOME/evolution

LICENSE=	GFDL GPLv2+ LGPL21+ MPL11 OPENLDAP
LICENSE_COMB=	multi
LICENSE_NAME_OPENLDAP=	OpenLDAP Public License
LICENSE_FILE_OPENLDAP=	${WRKSRC}/COPYING.OPENLDAP
LICENSE_PERMS_OPENLDAP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	highlight:textproc/highlight \
		iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libenchant-2.so:textproc/enchant2 \
		libgnome-autoar-gtk-0.so:archivers/gnome-autoar \
		libgspell-1.so:textproc/gspell \
		libical.so:devel/libical \
		libicuuc.so:devel/icu \
		libnotify.so:devel/libnotify \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libp11-kit.so:security/p11-kit \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	highlight:textproc/highlight \
		iso-codes>=0:misc/iso-codes

USES=		cmake compiler:c11 cpe desktop-file-utils gettext gnome \
		iconv:wchar_t libarchive localbase pathfix pkgconfig sqlite \
		tar:xz xorg
USE_GNOME=	atk cairo evolutiondataserver3 gdkpixbuf glib20 gnomedesktop3 \
		gtk30 intltool:build libxml2
USE_XORG=	x11
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome
CMAKE_ARGS=	-DENABLE_TEXT_HIGHLIGHT=YES \
		-DVERSION_COMMENT="FreeBSD GNOME Team" \
		-DWITH_ENCHANT_VERSION=2

GLIB_SCHEMAS=	org.gnome.evolution.addressbook.gschema.xml \
		org.gnome.evolution.bogofilter.gschema.xml \
		org.gnome.evolution.calendar.gschema.xml \
		org.gnome.evolution.gschema.xml \
		org.gnome.evolution.importer.gschema.xml \
		org.gnome.evolution.mail.gschema.xml \
		org.gnome.evolution.plugin.attachment-reminder.gschema.xml \
		org.gnome.evolution.plugin.autocontacts.gschema.xml \
		org.gnome.evolution.plugin.email-custom-header.gschema.xml \
		org.gnome.evolution.plugin.external-editor.gschema.xml \
		org.gnome.evolution.plugin.face-picture.gschema.xml \
		org.gnome.evolution.plugin.itip.gschema.xml \
		org.gnome.evolution.plugin.mail-notification.gschema.xml \
		org.gnome.evolution.plugin.prefer-plain.gschema.xml \
		org.gnome.evolution.plugin.publish-calendar.gschema.xml \
		org.gnome.evolution.plugin.sender-validator.gschema.xml \
		org.gnome.evolution.plugin.templates.gschema.xml \
		org.gnome.evolution.shell.gschema.xml \
		org.gnome.evolution.spamassassin.gschema.xml \
		org.gnome.evolution.text-highlight.gschema.xml

PLIST_SUB=	EVO_VERSION="1.2" CAL_API_VERSION="2.0"

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		CANBERRA LDAP MAPS MARKDOWN PST WEATHER YTNEF
OPTIONS_DEFAULT=	BOGOFILTER CANBERRA LDAP MARKDOWN WEATHER

SPAM_DESC=		Spam filter support
OPTIONS_GROUP=		SPAM
OPTIONS_GROUP_SPAM=	BOGOFILTER SPAMASSASSIN

LDAP_CMAKE_ON=	-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=	-DWITH_OPENLDAP=OFF
LDAP_USES=	ldap

YTNEF_DESC=		Support MS Outlook TNEF format
YTNEF_LIB_DEPENDS=	libytnef.so:converters/ytnef
YTNEF_CMAKE_BOOL=	ENABLE_YTNEF

WEATHER_DESC=		Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-4.so:net/libgweather4 \
			libgeocode-glib-2.so:net/geocode-glib2
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

SPAMASSASSIN_DESC=		SpamAssassin spam filtering
SPAMASSASSIN_CMAKE_ON=		-DWITH_SA_LEARN=${LOCALBASE}/bin/sa-learn \
				-DWITH_SPAMASSASSIN=${LOCALBASE}/spamassassin
SPAMASSASSIN_CMAKE_OFF=		-DWITH_SPAMASSASSIN=NO
SPAMASSASSIN_BUILD_DEPENDS=	spamassassin:mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamassassin:mail/spamassassin

BOGOFILTER_DESC=		Bogofilter spam filtering
BOGOFILTER_CMAKE_ON=		-DWITH_BOGOFILTER=${LOCALBASE}/bin/bogofilter
BOGOFILTER_CMAKE_OFF=		-DWITH_BOGOFILTER=OFF
BOGOFILTER_BUILD_DEPENDS=	bogofilter:mail/bogofilter
BOGOFILTER_RUN_DEPENDS=		bogofilter:mail/bogofilter

CANBERRA_DESC=		Canberra theme audio plugin
CANBERRA_LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
			libcanberra.so:audio/libcanberra
CANBERRA_CMAKE_BOOL=	ENABLE_CANBERRA

PST_DESC=		Outlook .pst importer
PST_CMAKE_BOOL=		ENABLE_PST_IMPORT
PST_BUILD_DEPENDS=	libpst>=0.6.58_1:mail/libpst
PST_RUN_DEPENDS=	libpst>=0.6.58_1:mail/libpst

MAPS_DESC=		Contact maps
MAPS_CMAKE_BOOL=	ENABLE_CONTACT_MAPS
MAPS_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
			libclutter-1.0.so:graphics/clutter \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
			libcogl.so:graphics/cogl \
			libgeocode-glib-2.so:net/geocode-glib2
MAPS_USES=		gl xorg
MAPS_USE=		GL=egl \
			XORG=xcomposite,xdamage,xext,xfixes,xi,xrandr

MARKDOWN_DESC=		Markdown support
MARKDOWN_CMAKE_ON=	-DENABLE_MARKDOWN=ON
MARKDOWN_CMAKE_OFF=	-DENABLE_MARKDOWN=OFF
MARKDOWN_LIB_DEPENDS=	libcmark.so:textproc/cmark

.include <bsd.port.mk>
