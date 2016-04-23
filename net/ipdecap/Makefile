# $FreeBSD$

PORTNAME=	ipdecap
PORTVERSION=	0.7.1
CATEGORIES=	net

MAINTAINER=	loic-freebsd@loicp.eu
COMMENT=	Decapsulate traffic encapsulated within GRE, IPIP, 6in4, ESP protocols

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/pcap/vlan.h:net/libpcap
LIB_DEPENDS=	libpcap.so:net/libpcap

PLIST_FILES=	bin/ipdecap\
		man/man1/ipdecap.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	lpefferkorn
GH_TAGNAME=	e9c6ba5

GNU_CONFIGURE=	yes
USES=		autoreconf gmake

regression-test: extract
	cd ${WRKSRC}/unit_tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
