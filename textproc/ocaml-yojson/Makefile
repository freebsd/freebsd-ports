PORTNAME=	yojson
PORTVERSION=	2.1.2
CATEGORIES=	textproc
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	JSON library for OCaml
WWW=		https://github.com/ocaml-community/yojson

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cppo:devel/ocaml-cppo \
		${SA_DIR}/seq/META:devel/ocaml-seq
RUN_DEPENDS=	${SA_DIR}/seq/META:devel/ocaml-seq

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-community
USE_OCAML=	yes
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages/index.mld

OPTIONS_DEFINE=		DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ydump \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
