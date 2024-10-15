PORTNAME=	alt-ergo
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.4
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Automatic solver of mathematical formulas for program verification
WWW=		https://alt-ergo.ocamlpro.com

LICENSE=	CeCILL-C
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license, version 1
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_powerpc64=	fails to compile: Assembler messages: /tmp/camlasm2822e8.s:10348: Error: operand out of range

BUILD_DEPENDS=	${LOCALBASE}/bin/menhir:devel/menhir \
		${SA_DIR}/dolmen/META:devel/ocaml-dolmen \
		${SA_DIR}/num/META:math/ocaml-num \
		${SA_DIR}/ocplib-simplex/META:math/ocaml-ocplib-simplex \
		${SA_DIR}/ppx_blob/META:devel/ocaml-ppx_blob \
		${SA_DIR}/psmt2-frontend/META:devel/ocaml-psmt2-frontend \
		${SA_DIR}/zarith/META:math/ocaml-zarith \
		${SA_DIR}/zip/META:archivers/ocaml-zip
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	${SA_DIR}/dolmen/META:devel/ocaml-dolmen \
		${SA_DIR}/num/META:math/ocaml-num \
		${SA_DIR}/ocplib-simplex/META:math/ocaml-ocplib-simplex \
		${SA_DIR}/ppx_blob/META:devel/ocaml-ppx_blob \
		${SA_DIR}/psmt2-frontend/META:devel/ocaml-psmt2-frontend \
		${SA_DIR}/zarith/META:math/ocaml-zarith \
		${SA_DIR}/zip/META:archivers/ocaml-zip

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	OCamlPro

USE_OCAML=		yes
OCAML_PACKAGES=		alt-ergo alt-ergo-lib alt-ergo-parsers
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE.md $p/README.md $p/odoc-pages/index.mld@} \
		alt-ergo/odoc-pages/index_common.mld \
		alt-ergo/odoc-pages/index_fmsimplex.mld

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_SUB=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version dev)/(version ${PORTVERSION})/" \
		${WRKSRC}/dune-project
	@${REINPLACE_CMD} \
		-e "s/ seq//" -e "s/ stdlib-shims//" \
		${WRKSRC}/src/bin/common/dune \
		${WRKSRC}/src/lib/dune \
		${WRKSRC}/src/parsers/dune

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/alt-ergo \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/alt-ergo-lib/AltErgoLib.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/alt-ergo-lib/__private__/alt_ergo_prelude/alt_ergo_prelude.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/alt-ergo-parsers/AltErgoParsers.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/alt-ergo/__private__/alt_ergo_common/alt_ergo_common.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/alt-ergo/plugins/FmSimplexPlugin.cmxs

do-test:
	@(cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${DUNE_ENV} ${DUNE_CMD} build @tests/gentest --auto-promote && \
		${SETENV} ${TEST_ENV} ${DUNE_ENV} ${DUNE_CMD} build @runtest @runtest-quick @runtest-ci)

.include <bsd.port.mk>
