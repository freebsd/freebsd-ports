PORTNAME=	pkt-gen
PORTVERSION=	g2022.02.10
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Packet sink/source using the netmap API

LICENSE=	BSD2CLAUSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	luigirizzo
GH_PROJECT=	netmap
GH_TAGNAME=	278045b
MAKEFILE=	GNUmakefile

OPTIONS_DEFINE=	PCAP
PCAP_DESC=	Support loading packets from pcap file
OPTIONS_DEFAULT=	PCAP
PCAP_MAKE_ARGS=	WITH_PCAP=1

PLIST_FILES=	bin/pkt-gen \
		bin/nmreplay

do-build:
	cd ${WRKSRC}/libnetmap && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${WRKSRC}/apps/pkt-gen && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${WRKSRC}/apps/nmreplay && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/pkt-gen/pkt-gen \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apps/nmreplay/nmreplay \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
