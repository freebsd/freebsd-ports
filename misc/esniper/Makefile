# New ports collection makefile for:	esniper
# Date created:		10 April 2005
# Whom:			Lewis Thompson <lewiz@compsoc.man.ac.uk>
#
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-17-1
CATEGORIES=	misc net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	A lightweight console application for sniping ebay auctions

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
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
