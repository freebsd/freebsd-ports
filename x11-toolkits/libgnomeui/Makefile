# New ports collection makefile for:	libgnomeui
# Date created:				07 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeui
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the GNOME GUI, a GNU desktop environment

LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/gnomekeyring \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${X11BASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libbonoboui
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_BISON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
PLIST_SUB=	GTK_VERSION="2.4.0"

.include <bsd.port.mk>
