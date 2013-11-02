# $FreeBSD$

PORTNAME=	libtorrent
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/libtorrent

MAINTAINER?=	az@FreeBSD.org
COMMENT?=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

CONFLICTS?=	libtorrent-devel-[0-9]* \
		rblibtorrent-[0-9]* \
		rblibtorrent-devel-[0-9]*

USE_AUTOTOOLS=	libtool
USES=	pathfix pkgconfig
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	KQUEUE IPV6
OPTIONS_DEFAULT=	KQUEUE
KQUEUE_DESC=	Use kqueue(2) support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

CONFIGURE_ARGS+=	--disable-debug

# Workaround to build on > 10.x
.if ${OSVERSION} >= 1000000
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--with-kqueue
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.post.mk>
