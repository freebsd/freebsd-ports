# New ports collection makefile for:   ocaml-pxp
# Date created:        29 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pxp
PORTVERSION=	1.1.94.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephane@freebsd.org
COMMENT=	Validating XML parser for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${LOCALBASE}/lib/ocaml/site-lib/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-without-wlex-compat -without-wlex

USE_REINPLACE=	yes

ALL_TARGET=	all opt

# to avoid a conflict with PACKAGES in bsd.port.mk
post-extract:
	${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e 's/PACKAGES/PXP_PACKAGES/'

.include <bsd.port.mk>
