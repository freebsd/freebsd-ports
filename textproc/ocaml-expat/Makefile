# Created by: Marwan Burelle <marwan.burelle@lri.fr
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A stub for the expat parser in OCaml

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
MAKE_ARGS=	EXPAT_LIBDIR=${LOCALBASE}/lib \
		EXPAT_INCDIR=${LOCALBASE}/include \
		CAML_INCDIR=${LOCALBASE}/lib/ocaml
ALL_TARGET=	all allopt doc
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
