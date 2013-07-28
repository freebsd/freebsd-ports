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

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir ${DOCSDIR} --prefix ${PREFIX} --mandir ${PREFIX}/man
USES=		gmake

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	PCRE
OPTIONS_DEFAULT=	PCRE

PCRE_CONFIGURE_ENABLE=	pcre
PCRE_BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
PCRE_RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

post-extract:
# For non-standard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,"make","${GMAKE}",' ${WRKSRC}/setup.ml

.include <bsd.port.mk>
