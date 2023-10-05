PORTNAME=	pkt-gen
PORTVERSION=	g2023.04.22
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Packet sink/source using the netmap API
WWW=		https://github.com/luigirizzo/netmap

LICENSE=	BSD2CLAUSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	luigirizzo
GH_PROJECT=	netmap
GH_TAGNAME=	eea4f11
MAKEFILE=	GNUmakefile

OPTIONS_DEFINE=	PCAP
PCAP_DESC=	Support loading packets from pcap file
OPTIONS_DEFAULT=	PCAP
PCAP_MAKE_ARGS=	WITH_PCAP=1

PLIST_FILES=	bin/pkt-gen \
		bin/nmreplay \
		share/man/man8/nmreplay.8.gz \
		share/man/man8/pkt-gen.8.gz

do-build:
	cd ${WRKSRC}/libnetmap && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${WRKSRC}/apps/pkt-gen && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${WRKSRC}/apps/nmreplay && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/pkt-gen/pkt-gen \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apps/nmreplay/nmreplay \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apps/pkt-gen/pkt-gen.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/apps/nmreplay/nmreplay.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
