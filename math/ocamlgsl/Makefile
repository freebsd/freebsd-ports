PORTNAME=	ocaml-gsl
DISTVERSION=	1.25.0
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface to GSL for the Objective Caml language
WWW=		https://mmottl.github.io/gsl-ocaml

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NOT_FOR_ARCHS=		armv6
NOT_FOR_ARCHS_REASON=	architectures with double-word alignment for doubles are not supported

BUILD_DEPENDS=		ocaml-base>=0:devel/ocaml-base \
			ocaml-stdio>=0:devel/ocaml-stdio
LIB_DEPENDS=		libgsl.so:math/gsl

USES=			blaslapack:openblas ocaml:dune pkgconfig
USE_OCAML=		YES
USE_OCAML_LDCONFIG=	YES
OCAML_LDLIBS=		gsl
OCAML_PACKAGES=		gsl

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	gsl-ocaml

MAKE_ENV=	GSL_CBLAS_LIB="${BLASLIB}"
DOCSDIR=	${OCAML_DOCSDIR}/gsl
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/gsl

PORTDOCS=	CHANGES.md LICENSE.md README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name gsl)/&\n(version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/gsl/dllgsl_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/gsl/gsl.cmxs
# cleanup from previous OCAML_LDLIBS
	@${ECHO_CMD} @postexec ${SED} -i "''" -e \
		"'/^${PREFIX:S#/#\/#g}\/${OCAML_SITELIBDIR:S#/#\/#g}\/ocaml-gsl$$/d'" \
		%D/${OCAML_LDCONF}  >> ${TMPPLIST}

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
