PORTNAME=	thcrut
PORTVERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	http://thc.org/releases/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local network discovery tool
WWW=		http://thc.org.segfault.net/

DEPRECATED=	BROKEN on all supported versions after the EOL of 12
EXPIRATION_DATE=	2023-12-31
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: ip_tcp_sync_addr
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: ip_tcp_sync_addr

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libnet=${LOCALBASE} \
			--sysconfdir=${DATADIR}

.include <bsd.port.mk>
