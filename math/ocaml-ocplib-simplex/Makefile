PORTNAME=	ocplib-simplex
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Alt-Ergo simplex solver library for Objective Caml
WWW=		https://ocamlpro.github.io/ocplib-simplex

LICENSE=	LGPL21+ # with a special exception to clause 6
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SA_DIR}/logs/META:devel/ocaml-logs
RUN_DEPENDS=	${SA_DIR}/logs/META:devel/ocaml-logs
TEST_DEPENDS=	${SA_DIR}/zarith/META:math/ocaml-zarith

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	OCamlPro
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version dev)/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/OcplibSimplex.cmxs

do-test:
	@(cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${DUNE_ENV} ${DUNE_CMD} runtest ${DUNE_ARGS})

.include <bsd.port.mk>
