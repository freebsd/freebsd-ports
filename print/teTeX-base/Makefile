# New ports collection makefile for:	teTeX
# Version required:	0.4
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@schiele-ct.de>
#
# $Id: Makefile,v 1.12 1996/12/13 07:18:48 tg Exp $
#

DISTNAME=	teTeX-src-0.4
PKGNAME=	teTeX-0.4
CATEGORIES=	print
MASTER_SITES=	${TETEX_SITE}/distrib/sources/
DISTFILES=	${TETEX_SRC} ${TETEX_LIB}

MAINTAINER=	br@schiele-ct.de

DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	${TETEX_SRC}
PATCH_DIST_STRIP=	-p1
NO_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini

TETEX_SITE=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX
TETEX_SRC=	teTeX-src-0.4pl3.tar.gz
TETEX_LIB=	teTeX-lib-0.4pl3.tar.gz
WRKLIB=		${WRKDIR}/teTeX

post-extract:
	@cd ${WRKDIR} && gzip -dc ${DISTDIR}/${DIST_SUBDIR}/${TETEX_LIB} | tar xf - 

pre-install:
	@chown -R bin:bin ${WRKLIB}/info ${WRKLIB}/man
	@chmod 444 ${WRKLIB}/info/* ${WRKLIB}/man/man1/* ${WRKLIB/man/man5/*
	@ (cd ${WRKLIB}; tar cf - info man/man1 man/man5) | (cd ${PREFIX}; tar xfp -)
	@ (cd ${WRKLIB}; tar cf - texmf) | (cd ${PREFIX}/share; tar xfp -)
	@install -c -m 644 -o bin -g bin ${WRKLIB}/texmf.cnf ${PREFIX}/share/texmf/web2c
	
post-install:
	@${SETENV} PREFIX=${PREFIX} /bin/sh files/install-note

.include <bsd.port.mk>
