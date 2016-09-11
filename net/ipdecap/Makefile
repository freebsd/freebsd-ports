# $FreeBSD$

PORTNAME=	ipdecap
PORTVERSION=	0.7.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	loic-freebsd@loicp.eu
COMMENT=	Decapsulate traffic encapsulated within GRE, IPIP, 6in4, ESP protocols

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/pcap/vlan.h:net/libpcap
LIB_DEPENDS=	libpcap.so.1:net/libpcap	# require ports libpcap	

PLIST_FILES=	bin/ipdecap\
		man/man1/ipdecap.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	lpefferkorn

GNU_CONFIGURE=	yes
USES=		autoreconf gmake ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

regression-test: extract
	cd ${WRKSRC}/unit_tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
