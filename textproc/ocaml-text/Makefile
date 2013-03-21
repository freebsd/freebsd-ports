# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	text
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/641/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml library for dealing with text

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--docdir ${DOCSDIR} --prefix ${PREFIX} --mandir ${PREFIX}/man
USE_GMAKE=		yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

OPTIONS_DEFINE=	PCRE
OPTIONS_DEFAULT=	PCRE

SA_DIR=			${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=	--enable-pcre
BUILD_DEPENDS+=		${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS+=		${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

.include <bsd.port.post.mk>
