# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	evolution
PORTVERSION=	2.32.1
PORTREVISION=	6
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3:${PORTSDIR}/security/nss \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		gtkimageview:${PORTSDIR}/x11-toolkits/gtkimageview
RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell

CONFLICTS=	evolution-3.[0-9]*

USE_BZIP2=	yes
USES=		bison desktop-file-utils gettext pathfix gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack evolutiondataserver gtkhtml3 \
		gnomedocutils ltasneededhack gnomedesktop
USE_AUTOTOOLS=	libtool
USE_GSTREAMER=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${PREFIX}/lib/evolution/${EVO_VERSION}
CONFIGURE_ARGS=	--enable-nss=yes \
		--enable-mono=no \
		--disable-nm \
		--with-sub-version=" FreeBSD GNOME Team Port"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	apps_evolution_addressbook.schemas \
		apps-evolution-attachment-reminder.schemas \
		apps_evolution_calendar.schemas \
		apps_evolution_email_custom_header.schemas \
		apps-evolution-mail-notification.schemas \
		apps-evolution-mail-prompts-checkdefault.schemas \
		apps_evolution_shell.schemas \
		apps-evolution-template-placeholders.schemas \
		bogo-junk-plugin.schemas \
		evolution-mail.schemas

EVO_VERSION=	2.32
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS_DEFINE=	LDAP CANBERRA SPAMASSASSIN
OPTIONS_DEFAULT=LDAP CANBERRA
CANBERRA_DESC=	Canberra theme audio plugin
SPAMASSASSIN_DESC=	SpamAssassin spam filtering

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
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
LIB_DEPENDS+=	canberra-gtk:${PORTSDIR}/audio/libcanberra
CONFIGURE_ARGS+=--enable-canberra=yes
PLIST_SUB+=	CANBERRA=""
.else
CONFIGURE_ARGS+=--enable-canberra=no
PLIST_SUB+=	CANBERRA="@comment "
.endif

# needs newer libpst version 0.6.41 or higher
#.if defined (WITH_PST)
#CONFIGURE_ARGS+=	--enable-pst-import
#BUILD_DEPENDS+=		lspst:${PORTSDIR}/mail/libpst
#RUN_DEPENDS+=		lspst:${PORTSDIR}/mail/libpst
#PLIST_SUB+=		PST=""
#.else
CONFIGURE_ARGS+=	--disable-pst-import
PLIST_SUB+=		PST="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e '/^plugins_standard_always/s/audio-inline//' \
	    	-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
		-e 's|-Wl,--no-undefined||g' \
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DG_DISABLE_DEPRECATED||g' \
		-e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/plugins/bogo-junk-plugin/bf-junk-filter.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/bin|g' \
		${WRKSRC}/plugins/sa-junk-plugin/em-junk-filter.c
	@${SH} ${FILESDIR}/fix-plugins.sh ${WRKSRC}

.include <bsd.port.mk>
