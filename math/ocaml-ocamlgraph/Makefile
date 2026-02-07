PORTNAME=	ocamlgraph
DISTVERSION=	2.1.0
CATEGORIES=	math
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Graph manipulation library for OCaml
WWW=		https://github.com/backtracking/ocamlgraph

LICENSE=	LGPL21 # with a special exception to clause 6
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=			ocaml:dune
USE_GITHUB=		yes
GH_ACCOUNT=		backtracking
DUNE_INSTALL_TARGETS=	ocamlgraph

ALL_TARGET=	ocamlgraph.install
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project
	@${REINPLACE_CMD} -e 's/ stdlib-shims//' ${WRKSRC}/src/dune

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/graph.cmxs
	# USES=ocaml:ldconfig cleanup
	@${ECHO_CMD} @postexec ${SED} -i "''" -e \
		"'/^${PREFIX:S#/#\/#g}\/${OCAML_SITELIBDIR:S#/#\/#g}\/ocamlgraph$$/d'" \
		%D/${OCAML_LDCONF}  >> ${TMPPLIST}

.include <bsd.port.mk>
