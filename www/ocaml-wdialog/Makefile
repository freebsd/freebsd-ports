# New ports collection makefile for:   ocaml-wdialog
# Date created:        1st May 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wdialog
PORTVERSION=	2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wdialog
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephane@freebsd.org
COMMENT=	Advanced system to create dialog-centric web applications

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/pxp-engine/pxp_engine.a:${PORTSDIR}/textproc/ocaml-pxp \
		${LOCALBASE}/lib/ocaml/site-lib/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/pxp-engine/pxp_engine.a:${PORTSDIR}/textproc/ocaml-pxp \
		${LOCALBASE}/lib/ocaml/site-lib/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
# Ocaml RPC port is not available for now, so we can't have the session daemon support
CONFIGURE_ARGS+=	-without-wd-session-daemon

ALL_TARGET=	all opt

.include <bsd.port.mk>
