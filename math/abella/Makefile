PORTNAME=	abella
DISTVERSION=	2.0.7
CATEGORIES=	math
MASTER_SITES=	http://abella-prover.org/distributions/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive theorem prover
WWW=		https://abella-prover.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		until https://github.com/abella-prover/abella/issues/154 is resolved

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild \
		ocamlfind:devel/ocaml-findlib

USES=		gmake

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
