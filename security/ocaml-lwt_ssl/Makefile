PORTNAME=	lwt_ssl
PORTVERSION=	1.2.0
CATEGORIES=	security
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OpenSSL asynchronously cooperative bindings for OCaml
WWW=		https://github.com/ocsigen/lwt_ssl

LICENSE=	LGPL21+ # with a special exception to clause 6

BUILD_DEPENDS=	ocaml-lwt>=5.7.0:devel/ocaml-lwt \
		${SA_DIR}/ssl/META:security/ocaml-ssl
RUN_DEPENDS=	ocaml-lwt>=5.7.0:devel/ocaml-lwt \
		${SA_DIR}/ssl/META:security/ocaml-ssl

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocsigen
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/lwt_ssl.cmxs

.include <bsd.port.mk>
