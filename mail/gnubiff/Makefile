# New ports collection makefile for:	gnubiff
# Date created:		3 May 2004
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	gnubiff
PORTVERSION=	2.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tim@bishnet.net
COMMENT=	A mail notification program for Gnome

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		fam.0:${PORTSDIR}/devel/fam

USE_X_PREFIX=	yes
USE_GNOME=	intlhack libglade2 esound
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnubiff.1
INFO=		gnubiff

.ifdef(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

# This application can dock in the GNOME panel, or it can not.
# Only install support if gnomepanel is already installed.
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel gconf2 gnomeprefix gnomehack
PKGNAMESUFFIX=		-gnome
PLIST_SUB+=		SHAREDIR="share/gnome"
PLIST_SUB+=		BONOBODIR="libdata/bonobo"
PLIST_SUB+=		WITH_GNOME=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=		SHAREDIR="share"
PLIST_SUB+=		BONOBODIR="lib/bonobo"
PLIST_SUB+=		WITH_GNOME="@comment "
.endif

.include <bsd.port.post.mk>
