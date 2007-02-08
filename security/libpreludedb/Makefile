# New ports collection makefile for:	libpreludedb
# Date created:			2005-10-14
# Whom:				Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	0.9.11.3
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Framework library for access to Prelude NIDS database

LIB_DEPENDS=	prelude.11:${PORTSDIR}/security/libprelude

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib \
			%%PREFIX%%/lib/libpreludedb/plugins/formats
USE_LDCONFIG=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=		PERL "Include Perl bindings" off \
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
USE_PYTHON=		2.3+
# Need to manually include bsd.python.mk, because USE_PYTHON is defined
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		WITH_MYSQL=""
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=		WITH_PGSQL=""
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--without-pgsql
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		WITH_SQLITE=""
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
