# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	wyvern
PORTVERSION=	2.2.11
PORTREVISION=	0
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.MysticWALL.COM/download/

MAINTAINER=	kouichi@MysticWALL.COM
COMMENT=	Small/powerful/lightweight/secure/embeddable HTTP server

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

LIB_DEPENDS=	sxml.1:${PORTSDIR}/textproc/sxml

DOCSRC=		${WRKSRC}/docs

USE_RC_SUBR=	wyvern
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/wyvern ${CONFIGURE_TARGET}
USE_OPENSSL=	yes
USE_BZIP2=	yes

MAKE_ARGS=	rcdir="${PREFIX}/etc/rc.d"

OPTIONS_DEFINE=	OPENSSL SQLITE3 PGSQL SUEXEC JAPANESE SYSCTL_PS SIMPLE_INDEXING \
		STRICT_PARSING
SUEXEC_DESC=	SuExec support
JAPANESE_DESC=	Japanese error messages
SYSCTL_PS_DESC=	Get process status with sysctl
SIMPLE_INDEXING_DESC=	Use simple indexing mode
STRICT_PARSING_DESC=	Parse request/response headers strictly

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800059
BROKEN=		does not build
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-openssl=yes
.endif

.if ${PORT_OPTIONS:MSQLITE3}
CONFIGURE_ARGS+=	--with-sqlite3=yes
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3:install
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-postgresql=yes
LIB_DEPENDS+=	pq.5:${PORTSDIR}/databases/postgresql82-client:install
PLIST_SUB+=	POSTGRESQL=""
.else
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

.if ${PORT_OPTIONS:MSUEXEC}
CONFIGURE_ARGS+=	--enable-suexec
.endif

.if ${PORT_OPTIONS:MJAPANESE}
CONFIGURE_ARGS+=	--enable-jp-mesg
.endif

.if ${PORT_OPTIONS:MSYSCTL_PS}
CONFIGURE_ARGS+=	--enable-sysctl-ps
.endif

.if ${PORT_OPTIONS:MSIMPLE_INDEXING}
CONFIGURE_ARGS+=	--enable-simple-indexing
.endif

.if ${PORT_OPTIONS:MSTRICT_PARSING}
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
