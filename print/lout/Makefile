# New ports collection makefile for: lout
# Version required:  3.13
# Date created:      10/22/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

DISTNAME=	lout-3.13
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}  \
		ftp://ftp.cs.usyd.edu.au/jeff/lout/
MASTER_SITE_SUBDIR=	support/lout

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lout c2lout
INSTALL_TARGET=	install installman installdoc

MAN1=		c2lout.1 lout.1

post-install:
	strip ${PREFIX}/bin/lout ${PREFIX}/bin/c2lout

.include <bsd.port.mk>
