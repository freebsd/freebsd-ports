PORTNAME=	farith
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Floating point number library for OCaml
WWW=		https://git.frama-c.com/pub/farith

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_hash/META:devel/ocaml-ppx_hash \
		${SA_DIR}/zarith/META:math/ocaml-zarith
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_hash/META:devel/ocaml-ppx_hash \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/zarith/META:math/ocaml-zarith

USES=		ocaml:dune
USE_GITLAB=	yes
GL_SITE=	https://git.frama-c.com
GL_ACCOUNT=	pub
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES LICENSE

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
