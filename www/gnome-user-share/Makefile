# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-user-share
PORTVERSION=	2.30.1
PORTREVISION=	4
CATEGORIES=	www deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libcanberra.so:${PORTSDIR}/audio/libcanberra \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_dnssd.so:${PORTSDIR}/www/mod_dnssd \
		console-kit-daemon:${PORTSDIR}/sysutils/consolekit

USES=		gettext gmake libtool pkgconfig tar:bzip2
USE_APACHE=	22+
USE_XORG=	sm
USE_GNOME=	gnomeprefix intlhack gtk20 gconf2 gnomedocutils nautilus2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-modules-path=${LOCALBASE}/${APACHEMODDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	desktop_gnome_file_sharing.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/httpd/modules|${LOCALBASE}/${APACHEMODDIR}|g' \
		${WRKSRC}/data/dav_user_*.conf

.include <bsd.port.mk>
