# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	evolution
PORTVERSION=	3.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libnotify.so:${PORTSDIR}/devel/libnotify

USE_XZ=		yes
USES=		desktop-file-utils bison gettext gmake pathfix pkgconfig \
		shebangfix
USE_GNOME=	gnomeprefix intlhack evolutiondataserver3 gtkhtml4 \
		gnomedocutils ltasneededhack gnomedesktop3
USE_AUTOTOOLS=	libtool
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/evolution/%%VERSION%%
CONFIGURE_ARGS=	--enable-nss=yes \
		--with-sub-version=" FreeBSD GNOME Team Port"
# gtkimageview needs to get a gtk3 release first.
CONFIGURE_ARGS+=--disable-image-inline
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	addressbook/tools/csv2vcard

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

EVO_VERSION=	3.6
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS_DEFINE=	LDAP WEATHER CANBERRA SPAMASSASSIN PST
OPTIONS_DEFAULT=LDAP WEATHER CANBERRA
CANBERRA_DESC=	Canberra theme audio plugin
WEATHER_DESC=	Weather calendar backend
SPAMASSASSIN_DESC=	SpamAssassin spam filtering
PST_DESC=	Outlook .pst importer
MAPS_DESC=	Contact maps

.include <bsd.port.options.mk>

USE_LDCONFIG=	${PREFIX}/lib/evolution/${EVO_VERSION}

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

.if ${PORT_OPTIONS:MWEATHER}
LIB_DEPENDS+=	libgweather-3.so:${PORTSDIR}/net/libgweather
CONFIGURE_ARGS+=--enable-weather
PLIST_SUB+=	WEATHER=""
.else
CONFIGURE_ARGS+=--disable-weather
PLIST_SUB+=	WEATHER="@comment "
.endif

.if ${PORT_OPTIONS:MSPAMASSASSIN}
RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/spamassassin
.endif

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=		krb5.26:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} \
			--with-krb5-includes=${HEIMDAL_HOME}/include
KRB5_LIB=		`${HEIMDAL_HOME}/bin/krb5-config gssapi --libs`
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if ${PORT_OPTIONS:MCANBERRA}
LIB_DEPENDS+=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
CONFIGURE_ARGS+=--enable-canberra=yes
PLIST_SUB+=	CANBERRA=""
.else
CONFIGURE_ARGS+=--enable-canberra=no
PLIST_SUB+=	CANBERRA="@comment "
.endif

.if ${PORT_OPTIONS:MPST}
CONFIGURE_ARGS+=	--enable-pst-import
BUILD_DEPENDS+=		libpst>=0.6.58_1:${PORTSDIR}/mail/libpst
RUN_DEPENDS+=		libpst>=0.6.58_1:${PORTSDIR}/mail/libpst
PLIST_SUB+=		PST=""
.else
CONFIGURE_ARGS+=	--disable-pst-import
PLIST_SUB+=		PST="@comment "
.endif

#.if ${PORT_OPTIONS:MMAPS}
# needs geoclue
#LIB_DEPENDS+=		champlain-0.12:${PORTSDIR}/graphics/libchamplain
#CONFIGURE_ARGS+=	--enable-contact-maps
#PLIST_SUB+=		MAPS=""
#.else
CONFIGURE_ARGS+=	--disable-contact-maps
PLIST_SUB+=		MAPS="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e '/^plugins_standard_always/s/audio-inline//' \
	    	-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
		-e 's|-Wl,--no-undefined||g' \
		-e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/modules/spamassassin/evolution-spamassassin.c \
		${WRKSRC}/modules/bogofilter/evolution-bogofilter.c
	@${SH} ${FILESDIR}/fix-plugins.sh ${WRKSRC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/${EVO_VERSION}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/3.6/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/3.6/plugins/liborg-gnome-*.so

.include <bsd.port.mk>
