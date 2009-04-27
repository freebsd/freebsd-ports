# New ports collection makefile for:    dpsearch
# Date created:         14.06.2004
# Whom:                 Maxim Zakharov <maxime@maxime.net.ru>
#
# $FreeBSD$
#

PORTNAME=	dpsearch
PORTVERSION=	4.52
CATEGORIES=	www
MASTER_SITES=	http://dataparksearch.googlecode.com/files/ \
		http://www.dataparksearch.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source search engine for Internet and Intranet sites

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/dataparksearch
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/dpsearch \
		--localstatedir=/var/dpsearch \
		--enable-mp3	\
		--with-zlib

SUB_FILES=	pkg-message

OPTIONS=	DPSEARCH_THREADS  "Enable pthreads"                       on  \
		DPSEARCH_SSL      "Enable SSL"                            on  \
		DPSEARCH_GUESSER  "Enable charset and language guesser"   on  \
		DPSEARCH_CHINESE  "Enable chinese charsets"               off \
		DPSEARCH_JAPANESE "Enable japanese charsets"              off \
		DPSEARCH_MECAB    "Enable MeCab japanese analyzer"        off \
		DPSEARCH_CHASEN   "Enable ChaSen japanese analyzer"       off \
		DPSEARCH_APACHE   "Enable mod_dpsearch for Apache"        off \
		DPSEARCH_IDN      "Enable Internationalized Domain Names" off \
		DPSEARCH_ASPELL   "Enable aspell support"                 off \
		DPSEARCH_PGSQL    "Use PostgreSQL  (mutually exclusive)"  off \
		DPSEARCH_MYSQL    "Use MySQL       (mutually exclusive)"  on \
		DPSEARCH_SQLITE   "Use SQLite      (mutually exclusive)"  off

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	PORTNAME="${PORTNAME}"

.if !defined(WITHOUT_DPSEARCH_THREADS)
CONFIGURE_ARGS+=--enable-pthreads
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=--disable-pthreads
.endif

.if !defined(WITHOUT_DPSEARCH_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=--without-aspell
.endif

.if !defined(NO_OPENSSL) && !defined(WITHOUT_DPSEARCH_SSL)
WITH_OPENSSL=	yes
.endif

.ifdef WITH_OPENSSL
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if defined(WITH_DPSEARCH_GUESSER)
CONFIGURE_ARGS+=--enable-charset-guesser
.endif

.if defined(WITH_DPSEARCH_CHASRETS)
CONFIGURE_ARGS+=--with-extra-charsets=all
.endif

.if defined(WITH_DPSEARCH_CHINESE)
CONFIGURE_ARGS+=--with-extra-charsets=chinese
.endif

.if defined(WITH_DPSEARCH_JAPANESE)
CONFIGURE_ARGS+=--with-extra-charsets=japanese
.endif

.if defined(WITH_DPSEARCH_MECAB)
LIB_DEPENDS+=	mecab.1:${PORTSDIR}/japanese/mecab
CONFIGURE_ARGS+=--enable-mecab
.endif

.if defined(WITH_DPSEARCH_CHASEN)
LIB_DEPENDS+=	chasen.2:${PORTSDIR}/japanese/chasen
CONFIGURE_ARGS+=--enable-chasen
.endif

.if defined(WITH_DPSEARCH_IDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=--enable-idn
.endif

.if defined(WITH_DPSEARCH_APACHE)
USE_APACHE=	1.3+
PLIST_SUB+=	APACHE=""
CONFIGURE_ARGS+=--enable-apache-module
.else
PLIST_SUB+=	APACHE="@comment "
.endif

.if !defined(WITH_DPSEARCH_PGSQL) && !defined(WITH_DPSEARCH_MYSQL) && !defined(WITH_DPSEARCH_SQLITE)
WITH_DPSEARCH_MYSQL=yes
pre-fetch:
	@${ECHO}
	@${ECHO} "Choose MySQL by default."
	@${ECHO}
.endif

.if defined(WITH_DPSEARCH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}

.elif defined(WITH_DPSEARCH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.elif defined(WITH_DPSEARCH_SQLITE)
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}

.endif

post-extract:
.if defined(NOPORTDOCS)
EXTRA_PATCHES+=      ${FILESDIR}/extra-patch-doc_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

pre-install:
	@${INSTALL} -d ${DATADIR}

post-install:
	@${CHMOD} 700 /var/dpsearch/cache
	@${ECHO_CMD} '@exec ${CHMOD} 700 /var/dpsearch/cache' >> ${TMPPLIST}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
