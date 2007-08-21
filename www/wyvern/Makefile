# New ports collection makefile for:   Wyvern
# Date created:        3 March 2001
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	wyvern
PORTVERSION=	2.2.7
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.MysticWALL.COM/download/

MAINTAINER=	kouichi@MysticWALL.COM
COMMENT=	Small/powerful/lightweight/secure/embeddable HTTP server

LIB_DEPENDS=	sxml.1:${PORTSDIR}/textproc/sxml

DOCSRC=		${WRKSRC}/docs

USE_RC_SUBR=	wyvern
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/wyvern ${CONFIGURE_TARGET}
USE_OPENSSL=	yes
USE_BZIP2=	yes

MAKE_ARGS=	rcdir="${PREFIX}/etc/rc.d"

OPTIONS=	OPENSSL "OpenSSL support" off \
		SQLITE3 "SQLite3 support" off \
		POSTGRESQL "PostgreSQL support" off \
		SUEXEC "SuExec support" off \
		JAPANESE "Use Japanese error messages" off \
		SYSCTL_PS "Get process status with sysctl" off \
		SIMPLE_INDEXING "Use simple indexing mode" off \
		STRICT_PARSING "Parse request/response headers strictly" off

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${OSREL} == 7.0
BROKEN=		doens't work; authors works on the problem
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=	--with-openssl=yes
.endif

.if defined(WITH_SQLITE3)
CONFIGURE_ARGS+=	--with-sqlite3=yes
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3:install
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-postgresql=yes
LIB_DEPENDS+=	pq.5:${PORTSDIR}/databases/postgresql82-client:install
PLIST_SUB+=	POSTGRESQL=""
.else
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

.if defined(WITH_SUEXEC)
CONFIGURE_ARGS+=	--enable-suexec
.endif

.if defined(WITH_JAPANESE)
CONFIGURE_ARGS+=	--enable-jp-mesg
.endif

.if defined(WITH_SYSCTL_PS)
CONFIGURE_ARGS+=	--enable-sysctl-ps
.endif

.if defined(WITH_SIMPLE_INDEXING)
CONFIGURE_ARGS+=	--enable-simple-indexing
.endif

.if defined(WITH_STRICT_PARSING)
CONFIGURE_ARGS+=	--enable-strict-parsing
.endif

post-extract:
	@${MV} ${DOCSRC}/htdocs/index.html ${DOCSRC}/htdocs/index.html-dist
	@${CP} -f ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}
	@${CP} -f ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}/lib
	@${CHMOD} a+x ${WRKSRC}/config.guess ${WRKSRC}/config.sub ${WRKSRC}/lib/config.guess ${WRKSRC}/lib/config.sub

post-install:
	${LN} -sf ${PREFIX}/wyvern/sbin/wyvern ${PREFIX}/sbin/
	if [ ! -f ${PREFIX}/wyvern/htdocs/index.html ]; then \
		${CP} -p ${PREFIX}/wyvern/htdocs/index.html-dist ${PREFIX}/wyvern/htdocs/index.html; \
	fi
	@${CAT} ${PKGMESSAGE}

certificate:
	if [ ! -d ${PREFIX}/wyvern/ssl ]; then \
		${MKDIR} ${PREFIX}/wyvern/ssl; \
	fi
	cd ${PREFIX}/wyvern && \
	openssl genrsa -des3 -rand /dev/random -out ssl/private.key 1024 && \
	openssl rsa -in ssl/private.key -out ssl/server.key && \
	openssl req -config conf/wyvern-ssl.cnf -new -key ssl/private.key \
		-x509 -days 90 -out ssl/server.crt

.include <bsd.port.post.mk>
