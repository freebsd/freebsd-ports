# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	ezmlm-idx
PORTVERSION=	7.2.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/ezmlm/archive/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of the ezmlm mailing list manager

LICENSE=	GPLv2

USES=		groff qmail:run

CONFLICTS=	ezmlm-0.*

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DB DOCS
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
DB_DESC=		Enable database extension support
MYSQL_DESC=		Build the MySQL extension
PGSQL_DESC=		Build the PostgreSQL extension
SQLITE_DESC=		Build the SQLite3 extension

.include <bsd.port.options.mk>

ALL_TARGET=	it

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include/mysql
EXTRACT_LIB+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lm
ALL_TARGET+=	mysql
PLIST_SUB+=	MYSQL="" PGSQL="@comment " SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include
EXTRACT_LIB+=	-L${LOCALBASE}/lib -lpq -lcrypt
ALL_TARGET+=	pgsql
PLIST_SUB+=	MYSQL="@comment " PGSQL="" SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=		sqlite
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include
EXTRACT_LIB+=	-L${LOCALBASE}/lib -lsqlite3
ALL_TARGET+=	sqlite3
PLIST_SUB+=	MYSQL="@comment " PGSQL="@comment " SQLITE=""
.else
PLIST_SUB+=	MYSQL="@comment " PGSQL="@comment " SQLITE="@comment "
.endif

CONFIG=		ezmlmglrc ezmlmrc ezmlmsubrc

DOCS=	BLURB CHANGES ChangeLog DOWNGRADE FAQ HISTORY INSTALL README \
	README.mysql README.pgsql README.std TODO UPGRADE

post-patch:
	@${ECHO_CMD} "/usr/sbin" > ${WRKSRC}/conf-cron
	@${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-bin
	@${ECHO_CMD} "${PREFIX}/etc/ezmlm" > ${WRKSRC}/conf-etc
	@${ECHO_CMD} "${PREFIX}/lib/ezmlm" > ${WRKSRC}/conf-lib
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s -rdynamic" > ${WRKSRC}/conf-ld
.if ${PORT_OPTIONS:MMYSQL}
	@${ECHO_CMD} "${CC} ${CFLAGS} ${EXTRACT_INCLUDE}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s -rdynamic ${EXTRACT_LIB}" > ${WRKSRC}/conf-ld
.elif ${PORT_OPTIONS:MPGSQL}
	@${ECHO_CMD} "${CC} ${CFLAGS} ${EXTRACT_INCLUDE}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s -rdynamic ${EXTRACT_LIB}" > ${WRKSRC}/conf-ld
.elif ${PORT_OPTIONS:MSQLITE}
	@${ECHO_CMD} "${CC} ${CFLAGS} ${EXTRACT_INCLUDE}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s -rdynamic ${EXTRACT_LIB}" > ${WRKSRC}/conf-ld
.endif
	@${ECHO_CMD} "${MANPREFIX}/man" > ${WRKSRC}/conf-man
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKSRC}/conf-qmail
	@${REINPLACE_CMD} -e 's,/etc/ezmlm/,${PREFIX}/etc/ezmlm/,' \
		${WRKSRC}/idx.h
	@${REINPLACE_CMD} -e "s:\(/installer\) \(\"\`head\):\1 ${STAGEDIR}\2:" \
	    -e "s:\(\"\`head -n 1 conf-etc\`\"/default\):${STAGEDIR}\1:" \
	    ${WRKSRC}/Makefile
pre-install:
	@${REINPLACE_CMD} -e '/\/cat/d' ${WRKSRC}/MAN

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/ezmlm
.for file in ${CONFIG}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/etc/ezmlm/${file}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
