# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	pidgin-birthday-reminder
PORTVERSION=	1.7
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	http://launchpadlibrarian.net/56075754/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Birthday reminder for Pidgin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	intltool
CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
