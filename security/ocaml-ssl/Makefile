# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	ssl
PORTVERSION=	0.4.6
CATEGORIES=	security devel
MASTER_SITES=	SF/savonet/ocaml-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OpenSSL bindings for OCaml

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
MAKE_ENV=	OCAMLFIND_INSTFLAGS="-ldconf ignore"
MAKE_JOBS_UNSAFE=	yes

USE_OPENSSL=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

ALL_TARGET=	all doc

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
