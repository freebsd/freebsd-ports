# New ports collection makefile for:	udmsearch
# Date created:		11/29/1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	udmsearch
PORTVERSION= 	2.2.1b
CATEGORIES=	www databases
MASTER_SITES=	http://mysearch.udm.net/Download/	\
		ftp://ftp.izhcom.ru/pub/unix/UdmSearch/	\
		http://mirror.kuenzler.ch/udmsearch/Download/

MAINTAINER=	dima@Chg.RU

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin/udmsearch \
		--sysconfdir=${PREFIX}/etc/udmsearch

.if defined(USE_POSTGRESQL)
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql
CONFIGURE_ARGS+=	--with-pgsql

.elif defined(USE_MSQL)
BUILD_DEPENDS=		${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql

.else
# default to mysql

LIB_DEPENDS=		mysqlclient.6:${PORTSDIR}/databases/mysql322-client
CONFIGURE_ARGS+=	--with-mysql

.if !defined(USE_MYSQL)
pre-fetch:
	@${ECHO}
	@${ECHO} "Defaulting to udmsearch with mysql support."
	@${ECHO}
	@${ECHO} "You may alternately build udmsearch with either msql or"
	@${ECHO} "postgresql support by invoking make with USE_MSQL=yes or"
	@${ECHO} "USE_POSTGRESQL=yes respectively."
	@${ECHO}
.endif

.endif

pre-install:
	${MKDIR} ${PREFIX}/bin/udmsearch
	${MKDIR} ${PREFIX}/etc/udmsearch

post-install:
	@cp -R ${WRKSRC}/create ${PREFIX}/etc/udmsearch
	@strip ${PREFIX}/sbin/indexer
	@strip ${PREFIX}/bin/udmsearch/search.cgi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
