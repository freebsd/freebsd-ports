# New ports collection makefile for:   ocaml-pxp
# Date created:        29 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pxp
DISTVERSION=	1.2.0test2
CATEGORIES=	textproc
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@stack.nl
COMMENT=	Validating XML parser for OCaml

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true

.if !defined(WITHOUT_ULEX)
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
