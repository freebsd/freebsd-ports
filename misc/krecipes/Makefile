# Created by: Henry Miller <hank@millerfarm.com>
# $FreeBSD$

PORTNAME=	krecipes
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	misc kde
MASTER_SITES=	SF

MAINTAINER=	hank@millerfarm.com
COMMENT=	Recipe database for cooks

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
