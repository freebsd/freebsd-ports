# New ports collection makefile for:	word2x
# Version required:	0.002
# Date created:		10 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/06/10 09:42:18 tg Exp $

DISTNAME=	word2x
PKGNAME=	word2x-0.002
CATEGORIES=	textproc
MASTER_SITES=	ftp://word2x.astra.co.uk/pub/word2x/

WRKSRC=		${WRKDIR}/word2x-0.002
MAINTAINER=	ports@FreeBSD.ORG

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

MAN1=	word2x.1

.include <bsd.port.mk>
