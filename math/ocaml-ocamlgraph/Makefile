# New ports collection makefile for:   ocaml-ocamlgraph
# Date created:        25 May 2004
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlgraph
PORTVERSION=	1.7
CATEGORIES=	math
MASTER_SITES=	http://ocamlgraph.lri.fr/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Graph manipulation library for OCaml

OPTIONS=	GUI "Include user programs: viewer and editor" off

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB+=	OCAMLGRAPHDIR="${OCAML_LIBDIR}/${PORTNAME}"

ALL_TARGET=	all
INSTALL_TARGET=	install install-findlib

.include <bsd.port.pre.mk>

.ifdef WITH_GUI
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	LABLGTK2=no
PLIST_SUB+=		GUI="@comment "
.endif

.ifndef NOPORTDOCS
ALL_TARGET+=	doc
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/VIEWER_DIR. doc/d' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} * ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
