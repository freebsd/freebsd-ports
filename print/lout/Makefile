# New ports collection makefile for: lout
# Version required:  3.08
# Date created:      10/22/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.1.1.1 1996/11/08 23:00:20 obrien Exp $
#

DISTNAME=	lout.3.08
PKGNAME=	lout-3.08
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}  \
		ftp://ftp.cs.usyd.edu.au/jeff/lout/
MASTER_SITE_SUBDIR=	support/lout/lout

MAINTAINER=	oly@world.std.com

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lout c2lout
INSTALL_TARGET=	install installman installdoc

MAN1=		c2lout.1 lout.1

post-install:
	strip $(PREFIX)/bin/lout
	strip $(PREFIX)/bin/c2lout

.include <bsd.port.mk>
