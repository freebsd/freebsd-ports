# New ports collection makefile for:	gnubiff
# Date created:		3 May 2004
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	gnubiff
PORTVERSION=	1.2.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tim@bishnet.net
COMMENT=	A mail notification program for Gnome

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GNOME=	libglade2 esound
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnubiff.1
INFO=		gnubiff

.if defined(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

.if defined(WITH_GNUBIFF_GNOME)
CONFIGURE_ARGS+=	--with-gnome
USE_GNOME+=		gnomepanel gconf2 gnomeprefix gnomehack
PLIST_SUB+=		WITH_GNUBIFF_GNOME=""
PLIST_SUB+=		SHAREDIR="share/gnome"
.else
PLIST_SUB+=		WITH_GNUBIFF_GNOME="@comment "
PLIST_SUB+=		SHAREDIR="share"
.endif

.include <bsd.port.mk>
