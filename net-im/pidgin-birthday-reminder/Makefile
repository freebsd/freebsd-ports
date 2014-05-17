# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	pidgin-birthday-reminder
PORTVERSION=	1.7
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://launchpadlibrarian.net/56075754/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Birthday reminder for Pidgin

LIB_DEPENDS=	libpurple.so:${PORTSDIR}/net-im/libpurple
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin


GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	intltool
CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
