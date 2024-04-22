PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.13
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml arithmetic library for arbitrary precision integers
WWW=		https://forge.ocamlcore.org/projects/zarith

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase:ldflags tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
GH_PROJECT=	Zarith
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	all
CONFIGURE_ENV=	DESTDIR=${STAGEDIR}

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	html
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=doc

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllzarith.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/zarith.cmxs

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${WRKSRC}/html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
