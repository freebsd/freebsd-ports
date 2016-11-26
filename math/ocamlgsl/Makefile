# Created by: Klaus T. Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	ocaml-gsl
DISTVERSIONPREFIX=v
DISTVERSION=	1.19.1
CATEGORIES=	math

MAINTAINER=	michipili@gmail.com
COMMENT=	Interface to GSL for the Objective Caml language

LICENSE=	GPLv3

LIB_DEPENDS=	libgsl.so:math/gsl
BUILD_DEPENDS=	gawk:lang/gawk \
		${OCAMLC_DEPEND}
RUN_DEPENDS=	ocamlfind:devel/ocaml-findlib

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	gsl-ocaml

USES=			gmake
USE_OCAML=		YES
USE_OCAML_FINDLIB=	YES
USE_OCAML_CAMLP4=	YES
USE_OCAML_LDCONFIG=	YES
OCAML_PKGDIRS=		gsl
HAS_CONFIGURE=		YES
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${LOCALBASE}/share/doc

OPTIONS_DEFINE=	DOCS

post-configure:
	@${ECHO_CMD} 'stagedir="${STAGEDIR}"' >> ${WRKSRC}/setup.data
	@${ECHO_CMD} 'docdir="$$datarootdir/doc/ocaml/$$pkg_name"' >> ${WRKSRC}/setup.data

.include <bsd.port.mk>
