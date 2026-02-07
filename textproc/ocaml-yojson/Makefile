PORTNAME=	yojson
DISTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	textproc
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	JSON library for OCaml
WWW=		https://github.com/ocaml-community/yojson/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-community

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages/index.mld

OPTIONS_DEFINE=	DOCS

DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ydump \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
