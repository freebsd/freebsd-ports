# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution/Makefile,v 1.222 2010/04/27 12:12:48 kwm Exp $
#

PORTNAME=	evolution
PORTVERSION=	2.30.1.1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3.1:${PORTSDIR}/security/nss \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview
RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver gtkhtml3 \
		desktopfileutils gnomedocutils ltasneededhack gnomedesktop \
		libgnomecanvas
USE_AUTOTOOLS=	libtool:22
USE_GSTREAMER=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/evolution/%%VERSION%%
CONFIGURE_ARGS=	--enable-nss=yes \
		--enable-mono=no \
		--disable-nm \
		--with-sub-version=" FreeBSD GNOME Team Port"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

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

EVO_VERSION=	2.30
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS=	PILOT "Enable Palm Pilot sync support" off \
		LDAP "Enable LDAP support" on \
		CANBERRA "Enable canberra plugin" on \
		SPAMASSASSIN "Enable SpamAssassin spam filtering" off

.include <bsd.port.pre.mk>

USE_LDCONFIG=	${PREFIX}/lib/evolution/${EVO_VERSION}

.if defined(WITH_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnome-pilot
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB+=	PILOT=""
.else
PLIST_SUB+=	PILOT="@comment "
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} \
			--with-krb5-includes=${HEIMDAL_HOME}/include
KRB5_LIB=		`${HEIMDAL_HOME}/bin/krb5-config gssapi --libs`
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if defined(WITH_CANBERRA)
LIB_DEPENDS+=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra
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
		-e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/plugins/bogo-junk-plugin/bf-junk-filter.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/bin|g' \
		${WRKSRC}/plugins/sa-junk-plugin/em-junk-filter.c
	@${SH} ${FILESDIR}/fix-plugins.sh ${WRKSRC}

.include <bsd.port.post.mk>
