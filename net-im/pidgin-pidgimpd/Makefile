# Created by: hrkfrd@googlemail.com
# $FreeBSD$

PORTNAME=	pidgimpd
PORTVERSION=	1.1.1
PORTREVISION=	12
CATEGORIES=	net-im audio
MASTER_SITES=	http://ayeon.org/projects/pidgimpd/
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PidgiMPD is a Pidgin plugin for monitoring/controlling MPD

LIB_DEPENDS=	libpurple.so:net-im/libpurple \
		libmpd.so:audio/libmpd
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/pidgin/pidgimpd.so

.include <bsd.port.mk>
