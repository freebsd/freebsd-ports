# Created by: ache
# $FreeBSD$

PORTNAME=	mnogosearch
PORTVERSION=	3.4.1
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	dpsearch-[0-9]* udmsearch-[0-9]* mguesser-[0-9]*

OPTIONS_DEFINE=	DOCS EXAMPLES THREADS SSL ASIAN SYSLOG

OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	PGSQL MYSQL SQLITE2 SQLITE3

OPTIONS_DEFAULT=	THREADS SSL SYSLOG SQLITE3

ASIAN_DESC=	Enable asian charsets
DATABASE_DESC=	Database backends
SYSLOG_DESC=	Send logs to syslog
SQLITE2_DESC=	Use SQLite 2.x
SQLITE3_DESC=	Use SQLite 3.x

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe gmake libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} \
		--localstatedir=/var/mnogosearch \
		--datadir=${DATADIR}

SUB_FILES+=	pkg-message

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	pgsql=${LOCALBASE}

SQLITE2_USES=	sqlite:2
SQLITE3_USES=	sqlite
SQLITE2_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE3_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USES+=	ssl
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-pthreads
.else
CONFIGURE_ARGS+=	--disable-pthreads
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MASIAN}
CONFIGURE_ARGS+=	--with-extra-charsets=all
.endif

.if ! ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--disable-syslog
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

PORTDATA=	*
PORTDOCS=	ChangeLog INSTALL README.html
PORTEXAMPLES=	README *.conf

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's#$$(DESTDIR)$$(prefix)/doc#${DOCSDIR}#' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e \
		's#^SUBDIRS = include src doc#SUBDIRS = include src#' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS:NREADME.html}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/samples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
