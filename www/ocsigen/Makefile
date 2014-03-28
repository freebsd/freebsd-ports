# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	ocsigen
PORTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	http://ocsigen.org/download/
DISTNAME=	ocsigenserver-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Web programming framework for OCaml

LICENSE=	LGPL21_SSLEX
LICENSE_NAME=	Lesser GPL 2.1 with a special OpenSSL exception clause
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${SA_DIR}/react/react.a:${PORTSDIR}/devel/ocaml-react \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		ocaml-net>=3:${PORTSDIR}/www/ocaml-net \
		ocaml-lwt>=2.4.2:${PORTSDIR}/devel/ocaml-lwt \
		${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit \
		${SA_DIR}/text/text.a:${PORTSDIR}/textproc/ocaml-text \
		ocaml-tyxml>=2.2.0:${PORTSDIR}/textproc/ocaml-tyxml

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes
OCAML_PKGDIRS=		ocsigenserver
OCAML_LDLIBS=		${OCAML_PKGDIRS:S/^/${OCAML_SITELIBDIR}\//}
MAKE_JOBS_UNSAFE=	yes

SA_DIR=			${PREFIX}/${OCAML_SITELIBDIR}

OPTIONS_DEFINE=		CAMLZIP
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	SQLITE DBM
OPTIONS_DEFAULT=	CAMLZIP SQLITE
OPTIONS_SUB=		yes
SQLITE_DESC=		Use sqlite as a database backend
DBM_DESC=		Use dbm as a database backend
CAMLZIP_DESC=		Use camlzip for compression

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-debug \
		--temproot ${STAGEDIR} \
		--enable-natdynlink \
		--ocsigen-user ${WWWOWN} \
		--ocsigen-group ${WWWGRP} \
		--bindir ${PREFIX}/bin \
		--mandir ${PREFIX}/man/man1 \
		--libdir ${SA_DIR} \
		--docdir ${DOCSDIR} \
		--sysconfdir ${PREFIX}/etc \
		--datadir ${PREFIX}/var/ocsigen \
		--staticpagesdir ${PREFIX}/share/ocsigen/www \
		--uploaddir /tmp

ALL_TARGET=	all
INSTALL_TARGET=	install

SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_BUILD_DEPENDS=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3
SQLITE_RUN_DEPENDS=	${SA_DIR}/sqlite3/sqlite3.a:${PORTSDIR}/databases/ocaml-sqlite3

DBM_CONFIGURE_WITH=	dbm
DBM_BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/dbm.a:${PORTSDIR}/databases/ocaml-dbm
DBM_RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/dbm.a:${PORTSDIR}/databases/ocaml-dbm

CAMLZIP_CONFIGURE_WITH=	camlzip
CAMLZIP_BUILD_DEPENDS=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip
CAMLZIP_RUN_DEPENDS=	ocaml-zip>=1.03_2:${PORTSDIR}/archivers/ocaml-zip

.include <bsd.port.options.mk>

# Docs fail with some kind of Netstring-pcre error, wasn't able to fix it
#.if ${PORT_OPTIONS:MDOCS}
#ALL_TARGET+=	doc
#INSTALL_TARGET+=install.doc
#PORTDOCS=	*
#.endif

do-configure:
	@(cd ${WRKSRC} && ${SH} configure ${CONFIGURE_ARGS})

.include <bsd.port.mk>
