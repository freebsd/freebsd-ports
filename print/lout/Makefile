# New ports collection makefile for: lout
# Version required:  3.10
# Date created:      10/22/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.2 1996/11/09 01:17:15 asami Exp $
#

DISTNAME=	lout.3.10
PKGNAME=	lout-3.10
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
	strip ${PREFIX}/bin/lout ${PREFIX}/bin/c2lout

.include <bsd.port.mk>
