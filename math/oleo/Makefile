# New ports collection makefile for:	oleo
# Version required:	1.6
# Date created:		3 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.11 1997/10/31 13:43:28 tg Exp $
#

DISTNAME=	oleo-1.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	oleo

MAINTAINER=	ports@FreeBSD.ORG

HAS_CONFIGURE=	yes
MAN1=		oleo.1

post-install:
	$(INSTALL_MAN) $(FILESDIR)/oleo.1 $(PREFIX)/man/man1

.include <bsd.port.mk>
