# New ports collection makefile for: ocsigen
# Date created: March 14, 2007
# Whom: Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$

PORTNAME=	ocsigen
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Web programming framework for OCaml

BUILD_DEPENDS=	ocaml-net<2:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
RUN_DEPENDS=	ocaml-net<2:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

OPTIONS=	OCAMLDUCE "Use OCamlDuce support" ON

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--name ${PORTNAME} \
		--disable-newocamlnet \
		--disable-nativecode \
		--disable-debug \
		--ocsigen-user ${WWWOWN} \
		--ocsigen-group ${WWWGRP} \
		--bindir ${PREFIX}/bin \
		--mandir ${PREFIX}/man/man1 \
		--libdir ${PREFIX}/share/examples \
		--docdir ${PREFIX}/share/doc \
		--sysconfdir ${PREFIX}/etc \
		--staticpagesdir ${PREFIX}/share/ocsigen/www \
		--uploaddir /tmp

INSTALL_TARGET=	fullinstall
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	docinstall
.endif

MAN1=		ocsigen.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OCAMLDUCE)
CONFIGURE_ARGS+=	--disable-ocamlduce
.else
BUILD_DEPENDS+=	${SA_DIR}/ocamlduce/ocamlduce.a:${PORTSDIR}/lang/ocamlduce
RUN_DEPENDS+=	${SA_DIR}/ocamlduce/ocamlduce.a:${PORTSDIR}/lang/ocamlduce
CONFIGURE_ARGS+=	--enable-ocamlduce
PLIST_FILES+=	${OCAML_SITELIBDIR}/ocsigen/ocsigenduce.cma \
		${OCAML_SITELIBDIR}/ocsigen/ocsigenduce.cmi \
		share/examples/ocsigen/exampleduce.cmo
.endif

.include <bsd.port.post.mk>
