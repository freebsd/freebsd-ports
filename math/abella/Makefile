# $FreeBSD$

PORTNAME=	abella
DISTVERSION=	2.0.6
CATEGORIES=	math
MASTER_SITES=	http://abella-prover.org/distributions/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive theorem prover

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild \
		ocamlfind:devel/ocaml-findlib

USES=		gmake

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
