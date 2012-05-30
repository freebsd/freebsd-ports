# New ports collection makefile for:    mnogosearch
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mnogosearch
PORTVERSION=	3.3.12
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

MAN1=		indexer.1
MAN5=		indexer.conf.5

OPTIONS_DEFINE=	THREADS SSL ASIAN SYSLOG

OPTIONS_MULTI=	database
OPTIONS_MULTI_database=	PGSQL MSQL MYSQL SQLITE2 SQLITE3

OPTIONS_DEFAULT=	THREADS SSL SYSLOG SQLITE3

ASIAN_DESC=	Enable asian charsets
SYSLOG_DESC=	Send logs to syslog
SQLITE2_DESC=	Use SQLite 2.x
SQLITE3_DESC=	Use SQLite 3.x

USE_LDCONFIG=	yes
USE_GNOME=	lthack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=--enable-shared \
		--sysconfdir=${ETCDIR} \
		--localstatedir=/var/mnogosearch \
		--datadir=${DATADIR}
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
MAKE_ENV+=	MKDIRPROG="${MKDIR}"

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
SHLIB_VER=	1

SUB_FILES+=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-pthreads
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	--disable-pthreads
CFLAGS+=	-DCONSOLE
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MASIAN}
CONFIGURE_ARGS+=	--with-extra-charsets=all
.endif

.if empty(PORT_OPTIONS:MSYSLOG)
CONFIGURE_ARGS+=	--disable-syslog
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMSQL}
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSQLITE2}
USE_SQLITE=	2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.endif

DOCS=		ChangeLog INSTALL
PORTDOCS=	*
PORTEXAMPLES=	README *.conf

post-patch:
.if !defined (NOPORTDOCS)
	@${REINPLACE_CMD} -e 's#$$(DESTDIR)$$(prefix)/doc#${DOCSDIR}#' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e \
		's#^SUBDIRS = include src doc#SUBDIRS = include src#' \
		${WRKSRC}/Makefile.in
.endif

pre-su-install:
	@${MKDIR} ${DATADIR}

post-install:
	${LN} -sf libmnogosearch.so \
		${PREFIX}/lib/libmnogosearch-${PORTVERSION:R}.so.${SHLIB_VER}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/mnogosearch
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.    for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.    endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/samples/* ${EXAMPLESDIR}/
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
