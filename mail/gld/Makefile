# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	gld
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.gasmi.net/down/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Greylisting daemon for Postfix

USE_RC_SUBR=	gld
HAS_CONFIGURE=	yes

SUB_FILES=	pkg-message

OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFINE=	LOCAL_DB_SERVER
OPTIONS_DEFAULT=	MYSQL
LOCAL_DB_SERVER_DESC=	RUN_DEPEND also on selected DB server

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
USE_MYSQL=	yes
.	if ${PORT_OPTIONS:MLOCAL_DB_SERVER}
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
SUB_LIST+=	PGSQL=
.	else
SUB_LIST+=	MYSQL=
.	endif
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
USE_PGSQL=	yes
.	if ${PORT_OPTIONS:MLOCAL_DB_SERVER}
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
SUB_LIST+=	MYSQL=
.	else
SUB_LIST+=	PGSQL=
.	endif
.endif

post-extract:
	@${RM} -f ${WRKSRC}/config.cache

post-patch:
	${REINPLACE_CMD} -e 's|\(@CC@\ \)-O2|\1${CFLAGS}|' \
		${WRKSRC}/Makefile.in

pre-build:
	${REINPLACE_CMD} -e 's,"/etc/gld.conf","${PREFIX}/etc/gld.conf",' ${WRKSRC}/gld.h
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gld ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/gld.conf ${PREFIX}/etc/gld.conf-dist
.if !exists(${PREFIX}/etc/gld.conf)
	${INSTALL_DATA} ${WRKSRC}/gld.conf ${PREFIX}/etc/gld.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in HISTORY LICENCE README table-whitelist.sql tables.mysql tables.pgsql
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
