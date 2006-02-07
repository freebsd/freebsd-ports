# New ports collection makefile for:	libgnomeui
# Date created:				07 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libgnomeui/Makefile,v 1.66 2005/09/07 04:43:08 marcus Exp $

PORTNAME=	libgnomeui
PORTVERSION=	2.12.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
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
USE_GNOME=	gnomeprefix gnomehack gnomehier libbonoboui ltverhack
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_BISON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
PLIST_SUB=	GTK_VERSION="2.4.0"

.include <bsd.port.mk>
