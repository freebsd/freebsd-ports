# New ports collection makefile for:	teTeX
# Version required:	0.4
# Date created:		27 August 1996
# Whom:			Bernd Rosauer <br@schiele-ct.de>
#
# $Id: Makefile,v 1.7 1996/07/23 12:36:55 tg Exp $
#

DISTNAME=	teTeX-src-0.4
PKGNAME=	teTeX-0.4
CATEGORIES+=	print
MASTER_SITES=	${TETEX_SITE}/distrib/sources/
DISTFILES=	teTeX-src-0.4pl2.tar.gz teTeX-lib-0.4pl1.tar.gz

MAINTAINER=	br@schiele-ct.de

RUN_DEPENDS=	wishx:${PORTSDIR}/lang/tclX75

DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	teTeX-src-0.4pl2.tar.gz
PATCH_DIST_STRIP=	-p1
NO_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini

TETEX_SITE=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX

.include <bsd.port.mk>
