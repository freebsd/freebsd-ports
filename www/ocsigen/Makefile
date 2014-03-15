# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	ocsigen
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Web programming framework for OCaml

BROKEN=		Does not build

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

OPTIONS_DEFINE=	SQLITE CAMLZIP
OPTIONS_DEFAULT=	CAMLZIP
CAMLZIP_DESC=	Use camlzip for compression

USES=		gmake
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
		--uploaddir /tmp \
		--disable-ocamlduce

ALL_TARGET=	depend all
INSTALL_TARGET=	installnodoc

MAN1=		ocsigen.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	docinstall
PORTDOCS=		*
.endif

.if ${PORT_OPTIONS:MSQLITE}
BUILD_DEPENDS+=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3
RUN_DEPENDS+=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3
CONFIGURE_ARGS+=	--enable-sqlite
PLIST_FILES+=	lib/ocsigen/extensions/ocsipersist-sqlite.cma
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if ${PORT_OPTIONS:MCAMLZIP}
CONFIGURE_ARGS+=	--enable-camlzip
BUILD_DEPENDS+=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip
RUN_DEPENDS+=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip
PLIST_FILES+=	lib/ocsigen/extensions/deflatemod.cmo
.else
CONFIGURE_ARGS+=	--disable-camlzip
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/ocsigen.conf ]; then \
	  ${CP} -p ${PREFIX}/etc/${PORTNAME}/ocsigen.conf.sample \
	    ${PREFIX}/etc/${PORTNAME}/ocsigen.conf; \
	fi

.include <bsd.port.mk>
