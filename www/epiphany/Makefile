# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.246 2011/04/30 20:43:27 mezz Exp $

PORTNAME=	epiphany
PORTVERSION=	2.30.6
PORTREVISION?=	4
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		${LOCALBASE}/share/icons/HighContrastLargePrint/index.theme:${PORTSDIR}/x11-themes/gnome-themes

CONFLICTS=	epiphany-3.[0-9]*

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
USES=		desktop-file-utils gettext pathfix gmake libtool pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomedesktop
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS+=--enable-introspection \
		--enable-compile-warnings=no \
		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

OPTIONS_DEFINE=	NSS SPELLCHECK SEED
OPTIONS_DEFAULT=NSS SPELLCHECK
NSS_DESC=	Import passwords from 2.26 and older on first run
SPELLCHECK_DESC=Enable spell checking by default
SEED_DESC=	Seed (JavaScript) support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=	libnss3.so:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-nss
.else
CONFIGURE_ARGS+=--disable-nss
.endif

.if ${PORT_OPTIONS:MSEED}
LIB_DEPENDS+=	libseed.so:${PORTSDIR}/devel/seed
CONFIGURE_ARGS+=--enable-seed
.endif

.if ${PORT_OPTIONS:MSPELLCHECK}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-embed_ephy-embed-prefs.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		-e 's|EPIPHANY_API_VERSION=2.29|EPIPHANY_API_VERSION=2.30|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
