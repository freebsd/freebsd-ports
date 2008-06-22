# New ports collection makefile for:   ocaml-ocamlgraph
# Date created:        25 May 2004
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlgraph
PORTVERSION=	0.99c
CATEGORIES=	math
MASTER_SITES=	http://ocamlgraph.lri.fr/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@stack.nl
COMMENT=	Graph manipulation library for OCaml

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

PLIST_SUB+=	OCAML_LIBDIR="${OCAML_LIBDIR}"

ALL_TARGET=	all
.ifndef NOPORTDOCS
ALL_TARGET+=	doc
PORTDOCS=	*

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} * ${DOCSDIR}
.endif

.include <bsd.port.mk>
