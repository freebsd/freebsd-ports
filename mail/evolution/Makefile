# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	2.2.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3.1:${PORTSDIR}/security/nss
RUN_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver gal2 \
		gtkhtml3 desktopfileutils
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-nss=yes \
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--with-sub-version=" FreeBSD GNOME Team Port" \
		--with-krb5=/usr
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_evolution_addressbook-${EVO_VERSION}.schemas \
		apps_evolution_calendar-${EVO_VERSION}.schemas \
		apps_evolution_shell-${EVO_VERSION}.schemas \
		evolution-mail-${EVO_VERSION}.schemas

EVO_VERSION=	2.2
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.2

OPTIONS=	PILOT "Enable Palm Pilot sync support" off \
		LDAP "Enable LDAP support" on \
		SPAMASSASSIN "Enable SpamAssassin spam filtering" off

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/lib/libgstreamer-0.8.so.5) || \
	defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
WITH_GSTREAMER=	yes
.endif

.if exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnomepilot2
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

.if defined(WITH_GSTREAMER)
LIB_DEPENDS+=	gstreamer-0.8.5:${PORTSDIR}/multimedia/gstreamer
PLIST_SUB+=	GSTREAMER=""
.else
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-glib-1.0:${PORTSDIR}/devel/dbus
PLIST_SUB+=	DBUS=""
.else
PLIST_SUB+=	DBUS="@comment "
.endif

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%EVO_VERSION%%|${EVO_VERSION}|' \
		${FILESDIR}/evolibs.sh > ${WRKDIR}/evolibs.sh

post-install:
	@${LN} -sf ${PREFIX}/bin/evolution-${EVO_VERSION} \
		${PREFIX}/bin/evolution
	@${INSTALL_SCRIPT} -m 555 ${WRKDIR}/evolibs.sh \
		${PREFIX}/etc/rc.d/000.evolibs.sh
	-@update-desktop-database

.include <bsd.port.post.mk>
