# New ports collection makefile for:	word2x
# Version required:	0.003
# Date created:		10 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/09/15 07:25:47 asami Exp $

DISTNAME=	word2x
PKGNAME=	word2x-0.003
CATEGORIES=	textproc
MASTER_SITES=	ftp://word2x.astra.co.uk/pub/word2x/

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

MAN1=	word2x.1

.include <bsd.port.mk>
