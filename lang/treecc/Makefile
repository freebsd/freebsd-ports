# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	treecc
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ahze@rgv.net
COMMENT=	Treecc program is designed to assist in the development of compilers

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAN1=		treecc.1
INFO=		treecc

post-install:
	@${LN} -sf treecc ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
