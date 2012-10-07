# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	0.9.15.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-technologies.com/download/releases/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for access to Prelude NIDS database

LIB_DEPENDS=	prelude.20:${PORTSDIR}/security/libprelude

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-gtk-doc=no
USE_LDCONFIG=	yes

MAN1=		preludedb-admin.1
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS MYSQL PERL PGSQL PYTHON SQLITE
OPTIONS_DEFAULT=MYSQL
PERL_DESC=	Include Perl bindings
PYTHON_DESC=	Include Python bindings
MYSQL_DESC=	Use MySQL backend
PGSQL_DESC=	Use PostgreSQL backend
SQLITE_DESC=	Use SQLite backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || exists(${LOCALBASE}/bin/mysql_config)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		WITH_MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL} || exists(${LOCALBASE}/bin/pg_config)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql
PLIST_SUB+=		WITH_PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgresql
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE} || exists(${LOCALBASE}/lib/libsqlite3.so)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		WITH_SQLITE=""
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

	@${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
