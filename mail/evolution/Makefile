# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution
PORTVERSION=	3.22.6
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite

LICENSE=	GFDL GPLv2+ LGPL21+ MPL OPENLDAP
LICENSE_COMB=	multi
LICENSE_NAME_OPENLDAP=	OpenLDAP Public License
LICENSE_FILE_OPENLDAP=	${WRKSRC}/COPYING.OPENLDAP
LICENSE_PERMS_OPENLDAP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	itstool:textproc/itstool \
		highlight:textproc/highlight
LIB_DEPENDS=	libnss3.so:security/nss \
		libgcr-3.so:security/gcr \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libgeocode-glib.so:net/geocode-glib \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libnspr4.so:devel/nspr \
		libical.so:devel/libical \
		libsecret-1.so:security/libsecret \
		libenchant.so:textproc/enchant \
		libp11-kit.so:security/p11-kit \
		libsoup-2.4.so:devel/libsoup \
		libcryptui.so:security/libcryptui \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	highlight:textproc/highlight \
		gnome-keyring>=3.0.0:security/gnome-keyring

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils bison gettext gmake gnome iconv:wchar_t \
		libtool localbase pathfix perl5 pkgconfig sqlite tar:xz
USE_GNOME=	cairo evolutiondataserver3 gnomedesktop3 intltool
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-nss=yes \
		--disable-autoar \
		--with-sub-version=" FreeBSD GNOME Team Port"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.evolution.gschema.xml \
		org.gnome.evolution.addressbook.gschema.xml \
		org.gnome.evolution.calendar.gschema.xml \
		org.gnome.evolution.importer.gschema.xml \
		org.gnome.evolution.mail.gschema.xml \
		org.gnome.evolution.shell.gschema.xml \
		org.gnome.evolution.bogofilter.gschema.xml \
		org.gnome.evolution.spamassassin.gschema.xml \
		org.gnome.evolution.plugin.attachment-reminder.gschema.xml \
		org.gnome.evolution.plugin.autocontacts.gschema.xml \
		org.gnome.evolution.plugin.email-custom-header.gschema.xml \
		org.gnome.evolution.plugin.external-editor.gschema.xml \
		org.gnome.evolution.plugin.face-picture.gschema.xml \
		org.gnome.evolution.plugin.itip.gschema.xml \
		org.gnome.evolution.plugin.mail-notification.gschema.xml \
		org.gnome.evolution.plugin.prefer-plain.gschema.xml \
		org.gnome.evolution.plugin.publish-calendar.gschema.xml \
		org.gnome.evolution.plugin.templates.gschema.xml

EVO_VERSION=	3.22
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS_DEFINE=	LDAP WEATHER CANBERRA PST
OPTIONS_DEFAULT=LDAP WEATHER CANBERRA BOGOFILTER
OPTIONS_GROUP=	SPAM
OPTIONS_GROUP_SPAM=SPAMASSASSIN BOGOFILTER

OPTIONS_SUB=	yes

CANBERRA_DESC=	Canberra theme audio plugin
WEATHER_DESC=	Weather calendar backend
SPAM_DESC=	Spam filter support
SPAMASSASSIN_DESC=	SpamAssassin spam filtering
BOGOFILTER_DESC=	Bogofilter spam filtering
PST_DESC=	Outlook .pst importer
MAPS_DESC=	Contact maps

LDAP_CONFIGURE_WITH=	openldap
LDAP_USE=	OPENLDAP=yes

WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CONFIGURE_ENABLE=	weather

SPAMASSASSIN_CONFIGURE_WITH=	spamassassin=${LOCALBASE}/bin/spamassassin \
				sa-learn=${LOCALBASE}/bin/sa-learn
SPAMASSASSIN_BUILD_DEPENDS=	spamassassin:mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamassassin:mail/spamassassin

BOGOFILTER_CONFIGURE_WITH=	bogofilter=${LOCALBASE}/bin/bogofilter
BOGOFILTER_BUILD_DEPENDS=	bogofilter:mail/bogofilter
BOGOFILTER_RUN_DEPENDS=	bogofilter:mail/bogofilter

CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
			libcanberra-gtk3.so:audio/libcanberra-gtk3
CANBERRA_CONFIGURE_ENABLE=	canberra

PST_CONFIGURE_ENABLE=	pst-import
PST_BUILD_DEPENDS=	libpst>=0.6.58_1:mail/libpst
PST_RUN_DEPENDS=	libpst>=0.6.58_1:mail/libpst

CONFIGURE_ARGS+=--disable-contact-maps
#MAPS_CONFIGURE_ENABLE=	contact-maps
#MAPS_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
#			libclutter-gtk-1.0.so:graphics/clutter-gtk3
#MAPS_BUILD_DEPENDS=	geoclue>=0:net/geoclue

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^plugins_standard_always/s/audio-inline//' \
		-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
		-e 's|-Wl,--no-undefined||g' \
		-e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/modules/spamassassin/evolution-spamassassin.c \
		${WRKSRC}/modules/bogofilter/evolution-bogofilter.c
#	@${SH} ${FILESDIR}/fix-plugins.sh ${WRKSRC}

.include <bsd.port.mk>
