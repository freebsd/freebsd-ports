PORTNAME=	expat
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stub for the expat parser in OCaml
WWW=		https://www.xs4all.nl/~mmzeeman/ocaml

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake ocaml:findlib,ldconfig

MAKE_ARGS=	EXPAT_LIBDIR=${LOCALBASE}/lib \
		EXPAT_INCDIR=${LOCALBASE}/include \
		CAML_INCDIR=${LOCALBASE}/lib/ocaml
ALL_TARGET=	all allopt doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
