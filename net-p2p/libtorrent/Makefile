# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME?=	libtorrent
PORTVERSION?=	0.9.3
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER?=	flz@FreeBSD.org
COMMENT?=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

CONFLICTS?=	libtorrent-devel-[0-9]*

USE_GCC=	3.4
USE_GNOME=	pkgconfig gnomehack
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

EXTRA_PATCHES?=	${.CURDIR}/files/stable-*

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-debug --with-openssl=${OPENSSLBASE}

post-patch:
	@${REINPLACE_CMD} -e 's/-O3/${CFLAGS}/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
