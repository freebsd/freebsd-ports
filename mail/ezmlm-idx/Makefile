# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	ezmlm-idx
PORTVERSION=	7.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ezmlm.org/archive/${PORTVERSION}/ \
		http://ezmlm.sericyb.com.au/archive/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of the ezmlm mailing list manager

MAKE_JOBS_UNSAFE=	yes

LICENSE=	GPLv2
LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

USES=		qmail:run

CONFLICTS=	ezmlm-0.*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DB DOCS
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
DB_DESC=		Enable database extension support
MYSQL_DESC=		Build the MySQL extension
PGSQL_DESC=		Build the PostgreSQL extension
SQLITE_DESC=		Build the SQLite3 extension


NO_STAGE=	yes
.include <bsd.port.options.mk>

ALL_TARGET=	it

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include/mysql
EXTRACT_LIB+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lm
ALL_TARGET+=	mysql
PLIST_SUB+=	MYSQL="" PGSQL="@comment " SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include
EXTRACT_LIB+=	-L${LOCALBASE}/lib -lpq -lcrypt
ALL_TARGET+=	pgsql
PLIST_SUB+=	MYSQL="@comment " PGSQL="" SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include
EXTRACT_LIB+=	-L${LOCALBASE}/lib -lsqlite3
ALL_TARGET+=	sqlite3
PLIST_SUB+=	MYSQL="@comment " PGSQL="@comment " SQLITE=""
.else
PLIST_SUB+=	MYSQL="@comment " PGSQL="@comment " SQLITE="@comment "
.endif

CONFIG=		ezmlmglrc ezmlmrc ezmlmsubrc

MAN1=	ezmlm-accept.1 ezmlm-archive.1 ezmlm-check.1 ezmlm-dispatch.1 \
	ezmlm-clean.1 ezmlm-cron.1 ezmlm-gate.1 ezmlm-get.1 \
	ezmlm-glconf.1 ezmlm-idx.1 ezmlm-issubn.1 ezmlm-limit.1 \
	ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-confirm.1 \
	ezmlm-moderate.1 ezmlm-reject.1 ezmlm-request.1 \
	ezmlm-return.1 ezmlm-send.1 ezmlm-split.1 ezmlm-store.1 \
	ezmlm-sub.1 ezmlm-tstdig.1 ezmlm-unsub.1 ezmlm-checksub.1 \
	ezmlm-warn.1 ezmlm-weed.1
MAN5=	ezmlm.5 ezmlmglrc.5 ezmlmrc.5 ezmlmsubrc.5
DOCS=	BLURB CHANGES ChangeLog DOWNGRADE FAQ HISTORY INSTALL README \
	README.mysql README.pgsql README.std TODO UPGRADE

post-patch:
	@${ECHO_CMD} /usr/sbin > ${WRKSRC}/conf-cron
	@${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO_CMD} ${PREFIX}/etc/ezmlm > ${WRKSRC}/conf-etc
	@${ECHO_CMD} ${PREFIX}/lib/ezmlm > ${WRKSRC}/conf-lib
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
.if defined(WITH_MYSQL)
	@${ECHO_CMD} ${CC} ${CFLAGS} ${EXTRACT_INCLUDE} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s ${EXTRACT_LIB} > ${WRKSRC}/conf-ld
.elif defined(WITH_PGSQL)
	@${ECHO_CMD} ${CC} ${CFLAGS} ${EXTRACT_INCLUDE} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s ${EXTRACT_LIB} > ${WRKSRC}/conf-ld
.elif defined(WITH_SQLITE)
	@${ECHO_CMD} ${CC} ${CFLAGS} ${EXTRACT_INCLUDE} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s ${EXTRACT_LIB} > ${WRKSRC}/conf-ld
.endif
	@${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO_CMD} ${QMAIL_PREFIX} > ${WRKSRC}/conf-qmail
	@${REINPLACE_CMD} -e 's,/etc/ezmlm/,${PREFIX}/etc/ezmlm/,' \
		${WRKSRC}/idx.h

pre-install:
	@${REINPLACE_CMD} -e '/\/cat/d' ${WRKSRC}/MAN

post-install:
	@${MKDIR} ${PREFIX}/etc/ezmlm
.for file in ${CONFIG}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc/ezmlm/${file}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
