# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution/Makefile 19797 2014-08-11 14:09:34Z gusi $

PORTNAME=	evolution
PORTVERSION=	3.12.5
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		highlight:${PORTSDIR}/textproc/highlight
LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3 \
		libgeocode-glib.so:${PORTSDIR}/net/geocode-glib \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	highlight:${PORTSDIR}/textproc/highlight

USES=		desktop-file-utils bison gettext gmake libtool \
		pathfix perl5 pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gnomeprefix gtkhtml4 \
		intlhack
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-nss=yes \
		--with-sub-version=" FreeBSD GNOME Team Port"
# gtkimageview needs to get a gtk3 release first.
CONFIGURE_ARGS+=--disable-image-inline
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

EVO_VERSION=	3.12
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

WEATHER_LIB_DEPENDS=	libgweather-3.so:${PORTSDIR}/net/libgweather
WEATHER_CONFIGURE_ENABLE=	weather

SPAMASSASSIN_CONFIGURE_ENABLE=	spamassassin
SPAMASSASSIN_BUILD_DEPENDS=	spamassassin:${PORTSDIR}/mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamassassin:${PORTSDIR}/mail/spamassassin

BOGOFILTER_CONFIGURE_ENABLE=	bogofilter
BOGOFILTER_BUILD_DEPENDS=	bogofilter:${PORTSDIR}/mail/bogofilter
BOGOFILTER_RUN_DEPENDS=	bogofilter:${PORTSDIR}/mail/bogofilter

CANBERRA_LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
CANBERRA_CONFIGURE_ENABLE=	canberra

PST_CONFIGURE_ENABLE=	pst-import
PST_BUILD_DEPENDS=	libpst>=0.6.58_1:${PORTSDIR}/mail/libpst
PST_RUN_DEPENDS=	libpst>=0.6.58_1:${PORTSDIR}/mail/libpst

CONFIGURE_ARGS+=--disable-contact-maps
#MAPS_CONFIGURE_ENABLE=	contact-maps
#MAPS_LIB_DEPENDS=	libchamplain-0.12.so:${PORTSDIR}/graphics/libchamplain \
#			libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3
#MAPS_BUILD_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue

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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/*/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/*/lib*.so

.include <bsd.port.mk>
