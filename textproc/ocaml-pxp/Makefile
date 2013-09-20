# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pxp
PORTVERSION=	1.2.4
CATEGORIES=	textproc
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Validating XML parser for OCaml

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

OPTIONS_DEFINE=	ULEX
OPTIONS_DEFAULT=ULEX
ULEX_DESC=	Include UTF-8 lexical analyzer support

USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MULEX}
BUILD_DEPENDS+=	${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex
RUN_DEPENDS+=	${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex
.endif

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-without-wlex-compat -without-wlex

ALL_TARGET=	all opt

# to avoid a conflict with PACKAGES in bsd.port.mk
post-extract:
	${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e 's/PACKAGES/PXP_PACKAGES/'

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/pxp* -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/ -type d -name 'pxp*' | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
