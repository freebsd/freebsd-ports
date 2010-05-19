# New ports collection makefile for:	esniper
# Date created:		10 April 2005
# Whom:			Lewis Thompson <lewiz@compsoc.man.ac.uk>
#
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-23-0
CATEGORIES=	misc net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	A lightweight console application for sniping ebay auctions

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config
USE_OPENSSL=	yes

MAN1=		esniper.1

PLIST_FILES=	bin/esniper

PORTEXAMPLES=	sample_auction.txt sample_config.txt

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_auction.txt ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_config.txt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
