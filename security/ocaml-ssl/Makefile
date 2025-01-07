PORTNAME=	ssl
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OpenSSL bindings for OCaml
WWW=		https://github.com/savonet/ocaml-ssl

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ocaml:dune,ldconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	savonet
GH_PROJECT=	ocaml-ssl

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ssl/dllssl_stubs.so

.include <bsd.port.mk>
