# $FreeBSD$

PORTNAME=	pkt-gen
PORTVERSION=	g2017.08.06
CATEGORIES=	net

MAINTAINER=	shurd@freebsd.org
COMMENT=	Packet sink/source using the netmap API

LICENSE=	BSD2CLAUSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	luigirizzo
GH_PROJECT=	netmap
GH_TAGNAME=	3c3ab5faa2ab9c89db09cd8339d0e96a1a78c41a
MAKEFILE=	GNUmakefile
WRKSRC_SUBDIR=	apps/pkt-gen
PATCH_WRKSRC=	${WRKSRC}/..

OPTIONS_DEFINE=	PCAP
PCAP_DESC=	Support loading packets from pcap file
OPTIONS_DEFAULT=PCAP
PCAP_MAKE_ARGS=	WITH_PCAP=1

PLIST_FILES=	bin/pkt-gen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkt-gen \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
