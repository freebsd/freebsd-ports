# New ports collection makefile for:	SuperLU
# Version required:	1.1
# Date created:         31 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id: Makefile,v 1.3 1998/12/10 17:24:33 vanilla Exp $
#

DISTNAME=	superlu_1.1
PKGNAME=	superlu-1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/pub/lapack/SuperLU/	\
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/cs.berkeley.edu/lapack/SuperLU/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libblas.a:${PORTSDIR}/math/blas

WRKSRC=		${WRKDIR}/SuperLU
ALL_TARGET=	superlulib
#
#	NOTE:	The Matlab interface was not built.
#

post-install:
	$(INSTALL_DATA) ${WRKSRC}/libsuperlu.* ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SuperLU
	${INSTALL_DATA} ${WRKSRC}/INSTALL/*.ps ${PREFIX}/share/doc/SuperLU
.endif
.include <bsd.port.mk>
