# New ports collection makefile for:	gnome-user-share
# Date created:				26 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-user-share
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LIB_DEPENDS=	howl:${PORTSDIR}/net/howl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_APACHE=	yes
APACHE_PORT=	www/apache2
USE_GNOME=	gnomeprefix gnomehack intlhack libglade2 gconf2
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	desktop_gnome_file_sharing.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/httpd/modules|${LOCALBASE}/libexec/apache2|g' \
		${WRKSRC}/dav_user.conf

.include <bsd.port.mk>
