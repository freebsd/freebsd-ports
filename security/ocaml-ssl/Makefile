# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	ssl
PORTVERSION=	0.5.3
CATEGORIES=	security devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSSL bindings for OCaml

USE_GITHUB=	yes
GH_ACCOUNT=	savonet
GH_PROJECT=	ocaml-ssl

USES=		autoreconf gmake ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
MAKE_ENV=	OCAMLFIND_INSTFLAGS="-ldconf ignore"
MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

ALL_TARGET=	all doc

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
