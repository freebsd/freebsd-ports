# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	tyxml
PORTVERSION=	2.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://ocsigen.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml XML typing library

USE_GMAKE=		yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

SA_DIR=			${LOCALBASE}/${OCAML_SITELIBDIR}

BUILD_DEPENDS+=		${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net
RUN_DEPENDS+=		${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

.include <bsd.port.post.mk>
