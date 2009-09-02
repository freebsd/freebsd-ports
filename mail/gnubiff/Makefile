# New ports collection makefile for:	gnubiff
# Date created:		3 May 2004
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	gnubiff
PORTVERSION=	2.2.11
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A mail notification program for Gnome

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	intlhack libglade2 esound
USE_GMAKE=	yes
USE_FAM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# CXXFLAGS needed to work round issue with gcc and openssl 0.9.8a
# /usr/local/include/openssl/sha.h:173: error: ISO C++ does not support `long long'
CXXFLAGS+=	"-Wno-long-long"

MAN1=		gnubiff.1
INFO=		gnubiff

.ifdef(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

.ifndef(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USE_GETTEXT=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

# This application can dock in the GNOME panel, or it can not.
# Only install support if gnomepanel is already installed.
WANT_GNOME=	yes

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
