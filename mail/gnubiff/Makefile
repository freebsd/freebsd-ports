# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	gnubiff
PORTVERSION=	2.2.13
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A mail notification program for Gnome

OPTIONS_DEFINE=	NLS

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	intlhack libglade2 esound
USES=		fam gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# CXXFLAGS needed to work round issue with gcc and openssl 0.9.8a
# /usr/local/include/openssl/sha.h:173: error: ISO C++ does not support `long long'
CXXFLAGS+=	"-Wno-long-long"

MAN1=		gnubiff.1
INFO=		gnubiff

.include <bsd.port.options.mk>

.ifdef(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

# This application can dock in the GNOME panel, or it can not.
# Only install support if gnomepanel is already installed.
WANT_GNOME=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel gconf2 gnomeprefix gnomehack
PKGNAMESUFFIX+=		-gnome
PLIST_SUB+=		BONOBODIR="libdata/bonobo"
PLIST_SUB+=		WITH_GNOME=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=		BONOBODIR="lib/bonobo"
PLIST_SUB+=		WITH_GNOME="@comment "
.endif

.include <bsd.port.post.mk>
