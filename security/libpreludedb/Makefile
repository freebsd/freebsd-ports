# New ports collection makefile for:	libpreludedb
# Date created:			2005-10-14
# Whom:				Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	0.9.15.3
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME} ${PORTNAME}/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for access to Prelude NIDS database

LIB_DEPENDS=	prelude.20:${PORTSDIR}/security/libprelude

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-gtk-doc=no
USE_LDCONFIG=	yes

MAN1=		preludedb-admin.1
PORTDOCS=	*

OPTIONS=	PERL "Include Perl bindings" off \
		PYTHON "Include Python bindings" off \
		MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend" off

.include <bsd.port.pre.mk>

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_MYSQL) || exists(${LOCALBASE}/bin/mysql_config)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		WITH_MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) || exists(${LOCALBASE}/bin/pg_config)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql
PLIST_SUB+=		WITH_PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgresql
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if defined(WITH_SQLITE) || exists(${LOCALBASE}/lib/libsqlite3.so)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		WITH_SQLITE=""
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

	@${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
