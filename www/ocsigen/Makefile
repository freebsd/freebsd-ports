# New ports collection makefile for: ocsigen
# Date created: March 14, 2007
# Whom: Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$

PORTNAME=	ocsigen
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Web programming framework for OCaml

BUILD_DEPENDS=	ocaml-net>=2:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		${SA_DIR}/lwt/lwt.a:${PORTSDIR}/devel/ocaml-lwt \
		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
RUN_DEPENDS=	ocaml-net>=2:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		${SA_DIR}/lwt/lwt.a:${PORTSDIR}/devel/ocaml-lwt \
		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

SA_DIR=		${PREFIX}/${OCAML_SITELIBDIR}

OPTIONS=	OCAMLDUCE "Use OCamlDuce support" ON \
		SQLITE "Use sqlite as a database backend" OFF \
		CAMLZIP "Use camlzip for compression" ON

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--name ${PORTNAME} \
		--disable-nativecode \
		--disable-debug \
		--ocsigen-user ${WWWOWN} \
		--ocsigen-group ${WWWGRP} \
		--bindir ${PREFIX}/bin \
		--mandir ${PREFIX}/man/man1 \
		--libdir ${SA_DIR} \
		--docdir ${DOCSDIR} \
		--sysconfdir ${PREFIX}/etc \
		--staticpagesdir ${PREFIX}/share/ocsigen/www \
		--uploaddir /tmp

ALL_TARGET=	depend all
INSTALL_TARGET=	installnodoc
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	docinstall
PORTDOCS=		*
.endif

MAN1=		ocsigen.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OCAMLDUCE)
CONFIGURE_ARGS+=	--disable-ocamlduce
.else
BUILD_DEPENDS+=	${SA_DIR}/ocamlduce/ocamlduce.a:${PORTSDIR}/lang/ocamlduce
RUN_DEPENDS+=	${SA_DIR}/ocamlduce/ocamlduce.a:${PORTSDIR}/lang/ocamlduce
CONFIGURE_ARGS+=	--enable-ocamlduce
PLIST_FILES+=	lib/ocsigen/examples/exampleduce.cmo \
		lib/ocsigen/extensions/eliom_duce.cma
.endif

.if defined(WITH_SQLITE)
BUILD_DEPENDS+=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3
RUN_DEPENDS+=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3
CONFIGURE_ARGS+=	--enable-sqlite
PLIST_FILES+=	lib/ocsigen/extensions/ocsipersist-sqlite.cma
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if defined(WITHOUT_CAMLZIP)
CONFIGURE_ARGS+=	--disable-camlzip
.else
CONFIGURE_ARGS+=	--enable-camlzip
BUILD_DEPENDS+=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip
RUN_DEPENDS+=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip
PLIST_FILES+=	lib/ocsigen/extensions/deflatemod.cmo
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/ocsigen.conf ]; then \
	  ${CP} -p ${PREFIX}/etc/${PORTNAME}/ocsigen.conf.sample \
	    ${PREFIX}/etc/${PORTNAME}/ocsigen.conf; \
	fi

.include <bsd.port.post.mk>
