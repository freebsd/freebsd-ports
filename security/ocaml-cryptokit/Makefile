# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptokit
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/891/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Variety of cryptographic primitives for Objective Caml

DESTDIRNAME=	destdir
HAS_CONFIGURE=	yes

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	doc
CONFIGURE_ARGS+=	--docdir ${OCAML_DOCSDIR}
.endif

post-patch:
	${REINPLACE_CMD} 's,"install","install" :: "-ldconf ignore",' \
		${WRKSRC}/setup.ml

.include <bsd.port.mk>
