# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	evolution
DISTVERSION=	3.40.2
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite

LICENSE=	GFDL GPLv2+ LGPL21+ MPL11 OPENLDAP
LICENSE_COMB=	multi
LICENSE_NAME_OPENLDAP=	OpenLDAP Public License
LICENSE_FILE_OPENLDAP=	${WRKSRC}/COPYING.OPENLDAP
LICENSE_PERMS_OPENLDAP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	itstool:textproc/itstool \
		iso-codes>=0:misc/iso-codes \
		highlight:textproc/highlight
LIB_DEPENDS=	libnss3.so:security/nss \
		libgcr-base-3.so:security/gcr \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libgnome-autoar-gtk-0.so:archivers/gnome-autoar \
		libsoup-2.4.so:devel/libsoup \
		libicuuc.so:devel/icu \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libnspr4.so:devel/nspr \
		libical.so:devel/libical \
		libsecret-1.so:security/libsecret \
		libenchant.so:textproc/enchant \
		libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libp11-kit.so:security/p11-kit \
		libcryptui.so:security/libcryptui \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify \
		libgspell-1.so:textproc/gspell
RUN_DEPENDS=	highlight:textproc/highlight \
		iso-codes>=0:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils cmake gettext gnome \
		iconv:wchar_t sqlite libarchive localbase pathfix pkgconfig \
		tar:xz xorg
USE_GNOME=	cairo evolutiondataserver3 gnomedesktop3 intltool
GNU_CONFIGURE=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_TEXT_HIGHLIGHT=YES \
		-DWITH_ENCHANT_VERSION=2 \
		-DVERSION_COMMENT="FreeBSD GNOME Team"

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

EVO_VERSION=	3.24
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP WEATHER CANBERRA PST YTNEF MAPS
OPTIONS_DEFAULT=LDAP WEATHER CANBERRA BOGOFILTER

SPAM_DESC=	Spam filter support
OPTIONS_GROUP=	SPAM
OPTIONS_GROUP_SPAM=SPAMASSASSIN BOGOFILTER

LDAP_CMAKE_ON=	-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=	-DWITH_OPENLDAP=OFF
LDAP_USE=	OPENLDAP=yes

YTNEF_DESC=		Support MS Outlook TNEF format
YTNEF_LIB_DEPENDS=	libytnef.so:converters/ytnef
YTNEF_CMAKE_BOOL=	ENABLE_YTNEF

WEATHER_DESC=		Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

SPAMASSASSIN_DESC=		SpamAssassin spam filtering
SPAMASSASSIN_CMAKE_ON=		-DWITH_SPAMASSASSIN=${LOCALBASE}/spamassassin \
				-DWITH_SA_LEARN=${LOCALBASE}/bin/sa-learn
SPAMASSASSIN_CMAKE_OFF=		-DWITH_SPAMASSASSIN=NO
SPAMASSASSIN_BUILD_DEPENDS=	spamassassin:mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamassassin:mail/spamassassin

BOGOFILTER_DESC=		Bogofilter spam filtering
BOGOFILTER_CMAKE_ON=		-DWITH_BOGOFILTER=${LOCALBASE}/bin/bogofilter
BOGOFILTER_CMAKE_OFF=		-DWITH_BOGOFILTER=OFF
BOGOFILTER_BUILD_DEPENDS=	bogofilter:mail/bogofilter
BOGOFILTER_RUN_DEPENDS=		bogofilter:mail/bogofilter

CANBERRA_DESC=		Canberra theme audio plugin
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
			libcanberra-gtk3.so:audio/libcanberra-gtk3
CANBERRA_CMAKE_BOOL=	ENABLE_CANBERRA

PST_DESC=	Outlook .pst importer
PST_CMAKE_BOOL=		ENABLE_PST_IMPORT
PST_BUILD_DEPENDS=	libpst>=0.6.58_1:mail/libpst
PST_RUN_DEPENDS=	libpst>=0.6.58_1:mail/libpst

MAPS_DESC=	Contact maps
MAPS_CMAKE_BOOL=	ENABLE_CONTACT_MAPS
MAPS_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
			libgeocode-glib.so:net/geocode-glib \
			libcogl.so:graphics/cogl \
			libclutter-1.0.so:graphics/clutter \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
			libchamplain-0.12.so:graphics/libchamplain
MAPS_USES=		gl xorg
MAPS_USE=		xorg=xcomposite,xdamage,xext,xfixes,xi,xrandr gl=egl

.include <bsd.port.mk>
