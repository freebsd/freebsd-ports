# New ports collection makefile for:	teTeX
# Version required:	0.3.3
# Date created:		30 Dec 1995
# Whom:			Bernd Rosauer <br@netland.sub.de>
#
# $Id: Makefile,v 1.1.1.1 1996/02/22 10:21:51 tg Exp $
#

DISTNAME=	teTeX-src-0.3.3
PKGNAME=	teTeX-0.3.3
CATEGORIES+=	print
MASTER_SITES=	${TETEX_SITE}/distrib/sources/ ${TETEX_SITE}/updates/texmf/
DISTFILES=	teTeX-src-0.3.3.tar.gz teTeX-lib-0.3.3.tar.gz \
		koma-script-2.3d.sh mflogo-1.5b.sh mathppl.sh \
		foiltex-2.0.1.sh dec-95pl1-update-u2.tar

PATCH_SITES=	${TETEX_SITE}/distrib/sources/
PATCHFILES=	teTeX-src-0.3.3-patch-001.gz teTeX-src-0.3.3-patch-002.gz \
		teTeX-src-0.3.3-patch-003.gz teTeX-src-0.3.3-patch-004.gz \
		teTeX-src-0.3.3-patch-005.gz teTeX-src-0.3.3-patch-006.gz \
		teTeX-src-0.3.3-patch-007.gz teTeX-src-0.3.3-patch-008.gz

MAINTAINER=	tetex-freebsd@informatik.uni-hannover.de

DISTDIR=	${PORTSDIR}/distfiles/teTeX
EXTRACT_ONLY=	teTeX-src-0.3.3.tar.gz
PATCH_DIST_STRIP=	-p1
NO_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini

TETEX_SITE=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX

.include <bsd.port.mk>
