# New ports collection makefile for:    licq
# Version required:                     0.61
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman
#
# $Id: Makefile,v 1.6 1999/05/02 20:21:28 mharo Exp $
#

DISTNAME=	licq-0.61
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wibble.net/pub/licq/srcs/ \
		ftp://licq.darkorb.net/srcs/ \
		ftp://ftp.fanfic.org/pub/licq/srcs/ \
		ftp://ftp.inter-i.uni-mainz.de/pub/licq/srcs/

MAINTAINER=	green@unixhelp.org

USE_QT=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		licq.1

post-install:
	@${MKDIR} ${PREFIX}/share/licq
	@${CP} ${WRKSRC}/contrib/licq.* ${WRKSRC}/contrib/viewurl* \
	 ${PREFIX}/share/licq
	@chmod 555 ${PREFIX}/share/licq/*
	@chown bin.bin ${PREFIX}/share/licq/*

.include <bsd.port.mk>
