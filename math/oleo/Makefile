# New ports collection makefile for:	oleo
# Version required:	1.6
# Date created:		3 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.10 1996/11/18 10:24:49 asami Exp $
#

DISTNAME=	oleo-1.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

HAS_CONFIGURE=	yes
MAN1=		oleo.1

post-install:
	$(INSTALL_MAN) $(FILESDIR)/oleo.1 $(PREFIX)/man/man1

.include <bsd.port.mk>
