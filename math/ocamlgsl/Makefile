# Created by: Klaus T. Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	ocamlgsl
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://oandrieu.nerim.net/ocaml/gsl/

MAINTAINER=	aehlig@linta.de
COMMENT=	An interface to GSL for the Objective Caml language

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		${OCAMLC_DEPEND}
RUN_DEPENDS=	ocamlfind:${PORTSDIR}/devel/ocaml-findlib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

INSTALL_TARGET=	install-findlib

USES=		gmake
USE_OCAML=	YES
MAKE_ENV+=	OCAMLDIR=${OCAML_LIBDIR}
MAKE_JOBS_UNSAFE=	yes
NO_OCAML_BUILDDEPENDS=	yes
USE_OCAML_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
