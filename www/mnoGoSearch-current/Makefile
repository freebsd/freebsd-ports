# New ports collection makefile for:    mnoGoSearch-current
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
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch

# To enable Cyrillic charset guesser, define this
# Guesser mode ignores charsets comes from HTTP header or <META> tag
.if defined(WITH_MNOGO_GUESSER)
CONFIGURE_ARGS+= --enable-charset-guesser
.endif

.if defined(WITH_MNOGO_PGSQL)
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}/pgsql

.elif defined(WITH_MNOGO_MSQL)
LIB_DEPENDS=            msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.elif defined(WITH_MNOGO_MYSQL)
LIB_DEPENDS=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.else
pre-fetch:
	@${ECHO}
	@${ECHO} "Defaulting to mnoGoSearch with built-in database."
	@${ECHO}
	@${ECHO} "You may alternately build mnoGoSearch with either msql, mysql or"
	@${ECHO} "postgresql support by invoking make with WITH_MNOGO_MSQL=yes,"
	@${ECHO} "WITH_MNOGO_MYSQL=yes or WITH_MNOGO_PGSQL=yes respectively."
	@${ECHO}
.endif

# Add missing msql DB initialization files
post-patch:
	${CP} ${FILESDIR}/msql_ispell.txt ${WRKSRC}/create/msql/ispell.txt
	${CP} ${FILESDIR}/msql_track.txt ${WRKSRC}/create/msql/track.txt

pre-install:
	@${MKDIR} ${PREFIX}/share/mnogosearch

post-install:
	${CP} -R ${WRKSRC}/create ${PREFIX}/share/mnogosearch
	${CHMOD} 700 /var/mnogosearch/cache
	${CHOWN} nobody.nogroup /var/mnogosearch/cache
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/mnogosearch
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
