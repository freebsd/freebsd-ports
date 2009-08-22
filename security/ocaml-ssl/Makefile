# New ports collection makefile for: ocaml-ssl
# Date created: March 14, 2007
# Whom: Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$

PORTNAME=	ssl
PORTVERSION=	0.4.3
CATEGORIES=	security devel
MASTER_SITES=	SF/savonet/ocaml-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OpenSSL bindings for OCaml

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}

USE_OPENSSL=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

ALL_TARGET=	all doc

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/html/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
