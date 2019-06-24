# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptokit
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/891/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Variety of cryptographic primitives for Objective Caml

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

DESTDIRNAME=	destdir
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir ${OCAML_DOCSDIR}

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	doc

post-patch:
	@${REINPLACE_CMD} 's,"install","install" :: "-ldconf ignore",' \
		${WRKSRC}/setup.ml
	@${REINPLACE_CMD} -e 's,uint32,&_t,' ${WRKSRC}/src/stubs-md5.c

.include <bsd.port.mk>
