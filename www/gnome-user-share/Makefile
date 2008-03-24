# New ports collection makefile for:	gnome-user-share
# Date created:				26 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gnome-user-share/Makefile,v 1.8 2008/02/24 20:36:08 marcus Exp $
#

PORTNAME=	gnome-user-share
PORTVERSION=	0.22
CATEGORIES=	www deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LIB_DEPENDS=	avahi-client:${PORTSDIR}/net/avahi-app

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_APACHE=	2.0+
USE_GNOME=	gnomeprefix gnomehack intlhack libglade2 gconf2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-howl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	desktop_gnome_file_sharing.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/httpd/modules|${LOCALBASE}/${APACHEMODDIR}|g' \
		${WRKSRC}/dav_user_${APACHE_VERSION:C/([0-9])$/.\1/}.conf

.include <bsd.port.mk>
