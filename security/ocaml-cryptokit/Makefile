# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>

PORTNAME=	cryptokit
PORTVERSION=	1.11
CATEGORIES=	security
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Variety of cryptographic primitives for Objective Caml

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild \
		${LOCALBASE}/${OCAML_SITELIBDIR}/zarith/META:math/ocaml-zarith

DESTDIRNAME=	destdir
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir ${OCAML_DOCSDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_TAGNAME=	release${PORTVERSION:S/.//g}

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	doc

.include <bsd.port.mk>
