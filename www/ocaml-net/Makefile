# New ports collection makefile for:   ocaml-net
# Date created:        01 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	net
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocamlnet
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephane@freebsd.org
COMMENT=	OCaml modules for Internet applications

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

WRKSRC=	${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	all opt

.include <bsd.port.mk>
