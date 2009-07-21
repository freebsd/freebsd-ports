# New ports collection makefile for:	gld
# Date created:				15 Jul 2004
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gld
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.gasmi.net/down/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Greylisting daemon for Postfix

USE_RC_SUBR=	gld
HAS_CONFIGURE=	yes

SUB_FILES=	pkg-message

OPTIONS=	MYSQL   "MySQL support"         on \
		PGSQL   "PgSQL support"         off \
		LOCAL_DB_SERVER "RUN_DEPEND also on selected DB server" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL) && defined(WITH_PGSQL)
BROKEN=		Cannot compile with both MySQL and PgSQL support
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
USE_MYSQL=	yes
.	if defined(WITH_LOCAL_DB_SERVER)
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
SUB_LIST+=	PGSQL=
.	else
SUB_LIST+=	MYSQL=
.	endif
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
USE_PGSQL=	yes
.	if defined(WITH_LOCAL_DB_SERVER)
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
SUB_LIST+=	MYSQL=
.	else
SUB_LIST+=	PGSQL=
.	endif
.endif

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in HISTORY LICENCE README table-whitelist.sql tables.mysql tables.pgsql
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
