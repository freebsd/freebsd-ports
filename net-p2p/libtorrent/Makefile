# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME?=	libtorrent
PORTVERSION?=	0.11.1
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/libtorrent

MAINTAINER?=	flz@FreeBSD.org
COMMENT?=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

CONFLICTS?=	libtorrent-devel-[0-9]*

USE_AUTOTOOLS=	libtool:15
USE_GCC=	3.4
USE_GNOME=	pkgconfig gnomehack
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

EXTRA_PATCHES?=	${.CURDIR}/files/stable-*

OPTIONS=	KQUEUE "Use kqueue(2) support" on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-debug --with-openssl=${OPENSSLBASE}

post-patch:
	@${REINPLACE_CMD} -e 's/-O3/${CFLAGS}/' ${WRKSRC}/configure

.if !defined(WITHOUT_KQUEUE)
CONFIGURE_ARGS+=	--with-kqueue
.endif

.include <bsd.port.post.mk>
