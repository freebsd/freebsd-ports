# New ports collection makefile for:	udmsearch
# Date created:		11/29/1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	udmsearch
PORTVERSION=	3.0.23
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://mysearch.udm.net/Download/	\
		ftp://ftp.izhcom.ru/pub/unix/UdmSearch/	\
		http://mirror.kuenzler.ch/udmsearch/Download/

MAINTAINER=	demon@FreeBSD.org

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch

.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}/pgsql

.elif defined(WITH_MSQL)
BUILD_DEPENDS=		${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.else
# default to mysql

LIB_DEPENDS=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.if !defined(WITH_MYSQL)
pre-fetch:
	@${ECHO}
	@${ECHO} "Defaulting to udmsearch with mysql support."
	@${ECHO}
	@${ECHO} "You may alternately build udmsearch with either msql or"
	@${ECHO} "postgresql support by invoking make with WITH_MSQL=yes or"
	@${ECHO} "WITH_PGSQL=yes respectively."
	@${ECHO}
.endif

.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/udmsearch

post-install:
	@cp -R ${WRKSRC}/create ${PREFIX}/share/udmsearch
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/udmsearch
	@strip ${PREFIX}/sbin/indexer
	@strip ${PREFIX}/share/udmsearch/search.cgi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
