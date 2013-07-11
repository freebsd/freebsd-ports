# Created by: Lewis Thompson <lewiz@compsoc.man.ac.uk>
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-28-0
PORTREVISION=	1
CATEGORIES=	misc net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ag-freebsd@muc.de
COMMENT=	Lightweight console application for sniping ebay auctions

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config
USE_OPENSSL=	yes

MAN1=		esniper.1

PLIST_FILES=	bin/esniper

PORTEXAMPLES=	sample_auction.txt sample_config.txt

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
