# New ports collection makefile for:    mnoGoSearch
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=       mnogosearch
PORTVERSION=    3.1.9
CATEGORIES=	www databases
MASTER_SITES=   http://search.mnogo.ru/Download/

MAINTAINER=     ache@FreeBSD.org

MAN1=		indexer.1
MAN5=		indexer.conf.5

NO_LATEST_LINK=	yes

INSTALLS_SHLIB= yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--enable-charset-guesser \
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch

.if defined(WITH_MNOGO_PGSQL)
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}/pgsql

.elif defined(WITH_MNOGO_MSQL)
LIB_DEPENDS=            msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.else
# default to mysql

LIB_DEPENDS=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.if !defined(WITH_MNOGO_MYSQL)
pre-fetch:
	@${ECHO}
	@${ECHO} "Defaulting to mnoGoSearch with mysql support."
	@${ECHO}
	@${ECHO} "You may alternately build mnoGoSearch with either msql or"
	@${ECHO} "postgresql support by invoking make with WITH_MNOGO_MSQL=yes or"
	@${ECHO} "WITH_MNOGO_PGSQL=yes respectively."
	@${ECHO}
.endif

.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/mnogosearch

post-install:
	@cp -R ${WRKSRC}/create ${PREFIX}/share/mnogosearch
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/mnogosearch
	@strip ${PREFIX}/sbin/indexer
	@strip ${PREFIX}/share/mnogosearch/search.cgi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
