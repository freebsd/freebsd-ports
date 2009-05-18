# New ports collection makefile for:    mnogosearch
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mnogosearch
PORTVERSION=	3.3.9
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_LDCONFIG=	yes
USE_GNOME=	lthack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=--enable-shared \
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch \
		--datadir=${PREFIX}/share/mnogosearch
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
MAKE_ENV+=	MKDIRPROG="${MKDIR}"

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
SHLIB_VER=	1

SUB_FILES+=	pkg-message

OPTIONS= \
		THREADS "Enable pthreads"		on  \
		SSL     "Enable SSL"			on  \
		ASIAN   "Enable asian charsets"	off \
		SYSLOG  "Send logs to syslog"   on  \
		PGSQL   "Use PGSQL"				off \
		MSQL    "Use MSQL"				off \
		MYSQL   "Use MySQL"				off \
		SQLITE  "Use SQLite 2.x"		on

.if !defined(NO_OPENSSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.ifdef WITHOUT_THREADS
CONFIGURE_ARGS+=	--disable-pthreads
CFLAGS+=	-DCONSOLE
.else
CONFIGURE_ARGS+=	--enable-pthreads
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
.endif

.if !defined(WITHOUT_SSL) || !defined(NO_OPENSSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.ifdef WITH_ASIAN
CONFIGURE_ARGS+=	--with-extra-charsets=all
.endif

.ifdef WITHOUT_SYSLOG
CONFIGURE_ARGS+=	--disable-syslog
.endif

.ifdef WITH_PGSQL
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
.endif

.ifdef WITH_MSQL
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}
.endif

.ifdef WITH_MYSQL
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.ifndef WITHOUT_SQLITE
USE_SQLITE=	2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.endif

.if defined(WITHOUT_SQLITE) && !defined(WITH_MYSQL) && \
    !defined(WITH_MSQL) && !defined(WITH_PGSQL)
BROKEN=	needs at least one database driver
.endif

DOCS=	INSTALL ChangeLog
PORTEXAMPLES=	README *.conf

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

pre-install:
	@${MKDIR} ${DATADIR}/

post-install:
	${LN} -sf libmnogosearch.so \
		${PREFIX}/lib/libmnogosearch-${PORTVERSION:R}.so.${SHLIB_VER}
	${CHMOD} 700 /var/mnogosearch/cache
	${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/mnogosearch
	${MKDIR} ${DOCSDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/samples/* ${EXAMPLESDIR}/
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
