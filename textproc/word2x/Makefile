# New ports collection makefile for:	word2x
# Version required:	0.002
# Date created:		10 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/09/14 02:45:06 thepish Exp $

DISTNAME=	word2x
PKGNAME=	word2x-0.002
CATEGORIES=	textproc
MASTER_SITES=	ftp://word2x.astra.co.uk/pub/word2x/

MAINTAINER=	ports@FreeBSD.ORG

BROKEN=		build

WRKSRC=		${WRKDIR}/word2x-0.002
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

MAN1=	word2x.1

.include <bsd.port.mk>
