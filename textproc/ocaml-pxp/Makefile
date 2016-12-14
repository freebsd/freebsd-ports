# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pxp
PORTVERSION=	1.2.7
CATEGORIES=	textproc
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser for OCaml

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:www/ocaml-net
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:www/ocaml-net

OPTIONS_DEFINE=	ULEX
OPTIONS_DEFAULT=ULEX
ULEX_DESC=	Include UTF-8 lexical analyzer support

USES=		gmake
USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true
USE_OCAML_CAMLP4=	true

ULEX_BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:devel/ocaml-ulex
ULEX_RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:devel/ocaml-ulex

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-without-wlex-compat -without-wlex

ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

# to avoid a conflict with PACKAGES in bsd.port.mk
post-extract:
	${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e 's/PACKAGES/PXP_PACKAGES/'

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/pxp* -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
