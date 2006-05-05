# New ports collection makefile for:	libpreludedb
# Date created:			2005-10-14
# Whom:				Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	0.9.7.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Framework library for access to Prelude NIDS database

LIB_DEPENDS=	prelude.[6-?]:${PORTSDIR}/security/libprelude

USE_GPG=		yes
SIG_SUFFIX=		.sig
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib \
			%%PREFIX%%/lib/libpreludedb/plugins/formats
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		WITH_PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		WITH_MYSQL=""
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-pgsql
PLIST_SUB+=		WITH_PGSQL=""
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--enable-sqlite3
PLIST_SUB+=		WITH_SQLITE=""
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
LDCONFIG_DIRS+=		%%PREFIX%%/lib/libpreludedb/plugins/sql
.else
CONFIGURE_ARGS+=	--disable-sqlite3
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
