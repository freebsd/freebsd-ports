# $FreeBSD$

PORTNAME=	ipdecap
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	loic-freebsd@loicp.eu
COMMENT=	Decapsulate traffic encapsulated within GRE, IPIP, 6in4, ESP protocols

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/pcap/vlan.h:net/libpcap
LIB_DEPENDS=	libpcap.so.1:net/libpcap	# require ports libpcap

USE_GITHUB=	yes
GH_ACCOUNT=	lpefferkorn

USES=		autoreconf gmake ssl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
TEST_TARGET=	check

PLIST_FILES=	bin/ipdecap\
		man/man1/ipdecap.1.gz

.include <bsd.port.mk>
