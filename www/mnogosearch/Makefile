# New ports collection makefile for:    mnogosearch
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mnogosearch
PORTVERSION=	3.2.32
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

MAN1=		indexer.1
MAN5=		indexer.conf.5

INSTALLS_SHLIB=	yes
USE_GNOME=	lthack
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--enable-shared \
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch \
		--datadir=${PREFIX}/share/mnogosearch
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
SHLIB_VER=	1

OPTIONS=	MNOGO_THREADS "Enable pthreads (unstable)"	off \
		MNOGO_SSL     "Enable SSL"			on  \
		MNOGO_ASIAN   "Enable asian charsets"		off \
		MNOGO_SYSLOG  "Send logs to syslog"             on  \
		MNOGO_PGSQL   "Use PGSQL"			off \
		MNOGO_MSQL    "Use MSQL"			off \
		MNOGO_MYSQL   "Use MySQL"			off \
		MNOGO_SQLITE  "Use SQLite 2.x"			on

.if !defined(NO_OPENSSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_MNOGO_THREADS)
CONFIGURE_ARGS+=	--enable-pthreads
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
.endif

.if !defined(WITHOUT_MNOGO_SSL) || !defined(NO_OPENSSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.ifdef WITH_MNOGO_ASIAN
CONFIGURE_ARGS+=	--with-extra-charsets=all
.endif

.ifdef WITHOUT_MNOGO_SYSLOG
CONFIGURE_ARGS+=	--disable-syslog
.endif

.ifdef WITH_MNOGO_PGSQL
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
.endif

.ifdef WITH_MNOGO_MSQL
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}
.endif

.ifdef WITH_MNOGO_MYSQL
LIB_DEPENDS+=		mysqlclient:${PORTSDIR}/databases/mysql41-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.ifndef WITHOUT_MNOGO_SQLITE
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.endif

.if defined(WITHOUT_MNOGO_SQLITE) && !defined(WITH_MNOGO_MYSQL) && \
    !defined(WITH_MNOGO_MSQL) && !defined(WITH_MNOGO_PGSQL)
BROKEN=	"You need to select at least one database driver"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

pre-install:
	@${MKDIR} ${PREFIX}/share/mnogosearch

post-install:
	${LN} -sf libmnogosearch.so \
		${PREFIX}/lib/libmnogosearch-${PORTVERSION:R}.so.${SHLIB_VER}
	${CHMOD} 700 /var/mnogosearch/cache
	${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/mnogosearch
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/samples/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
