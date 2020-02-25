# $FreeBSD$

PORTNAME=	addrwatch
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.2
CATEGORIES=	net

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Supports IP/Ethernet pairing for IPv4 and IPv6

LICENSE=	GPLv3

LIB_DEPENDS=	libevent.so:devel/libevent \
		libpcap.so:net/libpcap \
		libargp.so:devel/argp-standalone

USES=		autoreconf gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GITHUB=	yes
GH_ACCOUNT=	fln

PLIST_FILES=	bin/addrwatch \
		bin/addrwatch_stdout \
		bin/addrwatch_syslog \
		man/man8/addrwatch.8.gz

.include <bsd.port.mk>
