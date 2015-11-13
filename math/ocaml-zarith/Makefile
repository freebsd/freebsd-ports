# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zarith
PORTVERSION=	1.2.1
CATEGORIES=	math
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1199/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	marino@FreeBSD.org
COMMENT=	OCaml arithmetic library for arbitrary precision integers

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USES=			gmake perl5 shebangfix tar:tgz
USE_PERL5=		build
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
OCAMLFIND_LDCONF=	/dev/null
HAS_CONFIGURE=		yes
ALL_TARGET=		all
SHEBANG_FILES=		z_pp.pl
CONFIGURE_ENV+=		DESTDIR=${STAGEDIR}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

BROKEN_armv6=	binary /nxb-bin/usr/bin/cc: not found
PORTDOCS=	html
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=doc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${WRKSRC}/html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
