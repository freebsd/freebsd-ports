# New ports collection makefile for:   ocaml-ocamlgraph
# Date created:        25 May 2004
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlgraph
PORTVERSION=	0.81
CATEGORIES=	math
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/ocamlgraph/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	Graph manipulation library for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}

ALL_TARGET=	all
.ifndef NOPORTDOCS
ALL_TARGET+=	doc
.endif

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} * ${DOCSDIR}
.endif

.include <bsd.port.mk>
