# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	treecc
PORTVERSION=	0.1.6
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ahze@rgv.net

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_AUTOMAKE=	yes
MAN1=		treecc.1

pre-patch:
	@${REINPLACE_CMD} -e 's|etc doc tests examples|etc doc|g' \
		${WRKSRC}/Makefile.*

post-install:
	@${LN} -sf treecc ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
