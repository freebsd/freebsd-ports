# Created by: Klaus T. Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	ocaml-gsl
PORTVERSION=	1.15.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://bitbucket.org/mmottl/gsl-ocaml/downloads/
DISTNAME=	gsl-ocaml-${PORTVERSION}

MAINTAINER=	michipili@gmail.com
COMMENT=	Interface to GSL for the Objective Caml language

LICENSE=	GPLv3

LIB_DEPENDS=	libgsl.so:math/gsl
BUILD_DEPENDS=	gawk:lang/gawk \
		${OCAMLC_DEPEND}
RUN_DEPENDS=	ocamlfind:devel/ocaml-findlib

USES=			gmake
USE_OCAML=		YES
USE_OCAML_FINDLIB=	YES
USE_OCAML_CAMLP4=	YES
USE_OCAML_LDCONFIG=	YES
OCAML_PKGDIRS=		gsl
HAS_CONFIGURE=		YES
MAKE_JOBS_UNSAFE=	yes
WRKSRC=			${WRKDIR}/gsl-ocaml-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-configure:
	@${ECHO_CMD} 'stagedir="${STAGEDIR}"' >> ${WRKSRC}/setup.data
	@${ECHO_CMD} 'docdir="$$datarootdir/doc/ocaml/$$pkg_name"' >> ${WRKSRC}/setup.data

.include <bsd.port.mk>
