# New ports collection makefile for:	esniper
# Date created:		10 April 2005
# Whom:			Lewis Thompson <lewiz@compsoc.man.ac.uk>
#
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-10-0
CATEGORIES=	misc net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Lightweight tool for sniping ebay auctions

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN1=		esniper.1

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_auction.txt ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_config.txt ${EXAMPLESDIR}

.include <bsd.port.mk>
