# New ports collection makefile for:	teTeX
# Version required:	0.3.3
# Date created:		30 Dec 1995
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $Id: Makefile,v 1.5 1996/05/13 09:30:32 asami Exp $
#

DISTNAME=	teTeX-src-0.3.3
PKGNAME=	teTeX-0.3.3
CATEGORIES+=	print
MASTER_SITES=	${TETEX_SITE}/distrib/sources/ ${TETEX_SITE}/updates/texmf/
DISTFILES=	teTeX-src-0.3.3.tar.gz teTeX-lib-0.3.3.tar.gz \
		koma-script-2.3d.sh mflogo-1.5b.sh mathppl.sh \
		foiltex-2.0.1.sh dec-95pl1-update-u2.tar \
		apr-96-update.tar update-96-05-01.sh

PATCH_SITES=	${TETEX_SITE}/distrib/sources/
PATCHFILES=	teTeX-src-0.3.3-patch-001.gz teTeX-src-0.3.3-patch-002.gz \
		teTeX-src-0.3.3-patch-003.gz teTeX-src-0.3.3-patch-004.gz \
		teTeX-src-0.3.3-patch-005.gz teTeX-src-0.3.3-patch-006.gz \
		teTeX-src-0.3.3-patch-007.gz teTeX-src-0.3.3-patch-008.gz

MAINTAINER=	tetex-freebsd@informatik.uni-hannover.de

RUN_DEPENDS=	wishx:${PORTSDIR}/lang/tclX75

DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	teTeX-src-0.3.3.tar.gz
PATCH_DIST_STRIP=	-p1
NO_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini

TETEX_SITE=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX

.include <bsd.port.mk>
