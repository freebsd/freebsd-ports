# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.214 2009/10/25 20:22:54 marcus Exp $
#

PORTNAME=	epiphany
PORTVERSION=	2.28.2
PORTREVISION?=	0
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/gir-1.0/WebKit-1.0.gir:${PORTSDIR}/www/gir-repository-webkit
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2 \
		notify.1:${PORTSDIR}/devel/libnotify \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/gir-1.0/WebKit-1.0.gir:${PORTSDIR}/www/gir-repository-webkit \
		${LOCALBASE}/share/icons/HighContrastLargePrint/index.theme:${PORTSDIR}/x11-themes/gnome-themes

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop desktopfileutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS+=--enable-introspection
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} ${EXTRA_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} ${EXTRA_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

MAN1=		epiphany.1

OPTIONS=	NSS "Import passwords from 2.26 and older on first run" on \
		SEED "Enable seed support" off \
		SPELLCHECK "Enable spell checking by default" on

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--enable-compile-warnings=no
.endif

.if defined(WITH_NSS)
LIB_DEPENDS+=	nss3.1:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-nss
.else
CONFIGURE_ARGS+=--disable-nss
.endif

.if defined(WITH_SEED)
LIB_DEPENDS+=	seed.0:${PORTSDIR}/devel/seed
CONFIGURE_ARGS+=--enable-seed
.endif

.if defined(WITH_SPELLCHECK)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-embed_ephy-embed-prefs.c
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
