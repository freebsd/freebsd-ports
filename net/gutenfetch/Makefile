# New ports collection makefile for:	gutenfetch
# Date created:		22-Aug-2001
# Whom:			Russell Francis
#
# $FreeBSD$
#

PORTNAME=	gutenfetch
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://oak.cats.ohiou.edu/~rf358197/gutenfetch/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	rf358197@oak.cats.ohiou.edu
COMMENT=	Fetch listings and books from Project Gutenberg

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget/ \
		unzip:${PORTSDIR}/archivers/unzip/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		gutenfetch.1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gutenfetch

.include <bsd.port.mk>
