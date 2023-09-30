PORTNAME=	libpcap
PORTVERSION=	1.10.4
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library
WWW=		https://www.tcpdump.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		bison cpe gmake ssl

CPE_VENDOR=	tcpdump

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-dbus=no \
		--with-pcap=bpf
CONFIGURE_ENV+=	LEX=${LOCALBASE}/bin/flex
CFLAGS_amd64=	-fPIC
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	IPV6 REMOTE

OPTIONS_SUB=	yes

REMOTE_DESC=	Remote packet capture

IPV6_CONFIGURE_ENABLE=	ipv6
REMOTE_CONFIGURE_ENABLE=remote

.include <bsd.port.mk>
