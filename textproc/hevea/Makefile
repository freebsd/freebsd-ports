# New ports collection makefile for:	hevea
# Date created:		November 28 1999
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		hevea
PORTVERSION=		1.04
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/para/hevea/

MAINTAINER=		stephen@math.missouri.edu

BUILD_DEPENDS=		ocamlc:${PORTSDIR}/lang/ocaml

TEX_DIR=		${PREFIX}/share/texmf/tex/latex
TEXHASH=		${PREFIX}/bin/texhash

post-install:
	strip ${PREFIX}/bin/hevea
	strip ${PREFIX}/bin/hacha
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
