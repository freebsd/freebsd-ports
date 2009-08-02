# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME?=	libtorrent
PORTVERSION?=	0.12.4
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/libtorrent

MAINTAINER?=	flz@FreeBSD.org
COMMENT?=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

CONFLICTS?=	libtorrent-devel-[0-9]* \
		rblibtorrent-[0-9]* \
		rblibtorrent-devel-[0-9]*

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig gnomehack
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS=	KQUEUE "Use kqueue(2) support" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

CONFIGURE_ARGS+=	--disable-debug --with-openssl=${OPENSSLBASE}

post-patch:
	@${REINPLACE_CMD} -e 's/-O3/${CFLAGS}/' ${WRKSRC}/configure

.if !defined(WITHOUT_KQUEUE)
CONFIGURE_ARGS+=	--with-kqueue
.endif

.include <bsd.port.post.mk>
