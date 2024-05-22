PORTNAME=	cryptokit
PORTVERSION=	1.19
CATEGORIES=	security
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Variety of cryptographic primitives for Objective Caml
WWW=		https://github.com/xavierleroy/cryptokit

LICENSE=	LGPL20+ # with a special exception to clause 6
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/zarith/META:math/ocaml-zarith
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/zarith/META:math/ocaml-zarith

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_TAGNAME=	release${PORTVERSION:S/.//g}
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/cryptokit/dllcryptokit_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/cryptokit/cryptokit.cmxs

.include <bsd.port.mk>
