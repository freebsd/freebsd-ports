PORTNAME=	digestif
DISTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/mirage/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Cryptographic hashing library for OCaml
WWW=		https://github.com/mirage/digestif

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/eqaf/META:devel/ocaml-eqaf

USES=		ocaml:dune,ldconfig tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME} && \
		${STRIP_CMD} c/digestif_c.cmxs ocaml/digestif_ocaml.cmxs \
		dlldigestif_c_stubs.so

.include <bsd.port.mk>
