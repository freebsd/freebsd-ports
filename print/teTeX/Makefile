# New ports collection makefile for:	teTeX
# Version required:	0.3.4
# Date created:		20 July 1996
# Whom:			Bernd Rosauer <br@schiele-ct.de>
#
# $Id: Makefile,v 1.6 1996/05/27 06:54:07 asami Exp $
#

DISTNAME=	teTeX-src-0.3.4
PKGNAME=	teTeX-0.3.4
CATEGORIES+=	print
MASTER_SITES=	${TETEX_SITE}/distrib/sources/
DISTFILES=	teTeX-src-0.3.4.tar.gz teTeX-lib-0.3.4.tar.gz

MAINTAINER=	br@schiele-ct.de

RUN_DEPENDS=	wishx:${PORTSDIR}/lang/tclX75

DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	teTeX-src-0.3.4.tar.gz
PATCH_DIST_STRIP=	-p1
NO_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini

TETEX_SITE=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX

.include <bsd.port.mk>
