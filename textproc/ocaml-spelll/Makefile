PORTNAME=	spelll
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	textproc
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Fuzzy search library for OCaml
WWW=		https://github.com/c-cube/spell

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	c-cube

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	LICENSE README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune.*/&\n(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project
	@${REINPLACE_CMD} -e "s/(libraries seq stdlib-shims)//" \
		${WRKSRC}/src/dune

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
