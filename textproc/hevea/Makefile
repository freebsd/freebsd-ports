# New ports collection makefile for:	hevea
# Version required:	1.0.4
# Date created:		Novemeber 28 1999
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

DISTNAME=		hevea-1.04
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/para/hevea/

MAINTAINER=		stephen@math.missouri.edu

BUILD_DEPENDS=		ocamlc:${PORTSDIR}/lang/ocaml

TEX_DIR=		${PREFIX}/share/texmf/tex/latex
TEXHASH=		${PREFIX}/bin/texhash

post-install:
	strip ${PREFIX}/bin/hevea
	strip ${PREFIX}/bin/hacha
# This is a hack to get hevea.sty put in a place where latex
# will find it.  If you have a better way to do this, please
# tell me about it.
	${MKDIR} ${TEX_DIR}/hevea
	${CP} ${PREFIX}/lib/hevea/hevea.sty ${TEX_DIR}/hevea/hevea.sty
.if exists(${TEXHASH})
	${TEXHASH}
.endif

.include <bsd.port.mk>
