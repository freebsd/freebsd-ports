# New ports collection makefile for:   ocaml-pxp
# Date created:        29 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pxp
PORTVERSION=	1.1.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephane@freebsd.org
COMMENT=	Validating XML parser for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_GMAKE=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	all opt

.include <bsd.port.mk>
