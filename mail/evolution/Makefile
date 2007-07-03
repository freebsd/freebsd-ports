# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution/Makefile,v 1.134 2007/03/13 05:41:38 marcus Exp $
#

PORTNAME=	evolution
PORTVERSION=	2.10.3
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3.1:${PORTSDIR}/security/nss
RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver \
		gtkhtml3 desktopfileutils gnomedocutils libgnomeprintui
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/evolution/%%VERSION%%
CONFIGURE_ARGS=	--enable-nss=yes \
		--enable-mono=no \
		--with-sub-version=" FreeBSD GNOME Team Port"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_evolution_addressbook-${EVO_VERSION}.schemas \
		apps_evolution_calendar-${EVO_VERSION}.schemas \
		apps-evolution-mail-prompts-checkdefault-${EVO_VERSION}.schemas \
		apps_evolution_shell-${EVO_VERSION}.schemas \
		evolution-mail-${EVO_VERSION}.schemas

EVO_VERSION=	2.10
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.10

OPTIONS=	PILOT "Enable Palm Pilot sync support" off \
		LDAP "Enable LDAP support" on \
		SPAMASSASSIN "Enable SpamAssassin spam filtering" off

.include <bsd.port.pre.mk>

USE_LDCONFIG=	${PREFIX}/lib/evolution/${EVO_VERSION}
.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
WITH_DBUS=	yes
.endif

.if exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnome-pilot
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB+=	PILOT:=""
.else
PLIST_SUB+=	PILOT:="@comment "
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

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS=""
.else
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${OSVERSION} >= 500000 && !defined(NO_KERBEROS) && \
	exists(/usr/lib/libkrb5.so)
CONFIGURE_ARGS+=	--with-krb5=/usr
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --with-krb5-includes=${HEIMDAL_HOME}/include
.else
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^plugins_standard_always/s/audio-inline//' \
	    	${WRKSRC}/configure

post-install: install-ldconfig-file
	${MKDIR} ${PREFIX}/include/evolution-${EVO_VERSION}/composer
	${INSTALL_DATA} ${WRKSRC}/composer/e-msg*.h ${PREFIX}/include/evolution-${EVO_VERSION}/composer
	${INSTALL_DATA} ${WRKSRC}/composer/Editor.h ${PREFIX}/include/evolution-${EVO_VERSION}/composer
	@${LN} -sf ${PREFIX}/bin/evolution-${EVO_VERSION} \
		${PREFIX}/bin/evolution
	-@update-desktop-database

.include <bsd.port.post.mk>
