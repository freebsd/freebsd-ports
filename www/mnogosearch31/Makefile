# New ports collection makefile for:    mnogosearch
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mnogosearch
PORTVERSION=    3.1.20
PORTREVISION=   3
CATEGORIES=	www databases
MASTER_SITES=   http://www.mnogosearch.org/Download/

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_LIBTOOL=    yes
INSTALLS_SHLIB= yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-phrase \
		--enable-shared \
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch

.if !defined(WITHOUT_MNOGO_THREADS)
CONFIGURE_ARGS+= --enable-freebsd-pthreads
CFLAGS+=        ${PTHREAD_CFLAGS}
CONFIGURE_ENV=  LIBS="${PTHREAD_LIBS}"
.endif

.if !defined(NO_OPENSSL) && !defined(WITHOUT_MNOGO_SSL)
USE_OPENSSL=    yes
.endif

.ifdef USE_OPENSSL
CONFIGURE_ARGS+= --with-openssl=${OPENSSLBASE}
.endif

# To enable Cyrillic charset guesser, define this
# Guesser mode ignores charsets comes from HTTP header or <META> tag
.if defined(WITH_MNOGO_GUESSER)
CONFIGURE_ARGS+= --enable-charset-guesser
.endif

.if defined(WITH_MNOGO_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}

.elif defined(WITH_MNOGO_MSQL)
LIB_DEPENDS=            msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.elif defined(WITH_MNOGO_MYSQL)
LIB_DEPENDS=            mysqlclient:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.else
CONFIGURE_ARGS+=        --with-built-in

pre-fetch:
	@${ECHO}
	@${ECHO} "Defaulting to mnoGoSearch with built-in database."
	@${ECHO}
	@${ECHO} "You may alternately build mnoGoSearch with either msql, mysql or"
	@${ECHO} "postgresql support by invoking make with WITH_MNOGO_MSQL=yes,"
	@${ECHO} "WITH_MNOGO_MYSQL=yes or WITH_MNOGO_PGSQL=yes respectively."
	@${ECHO}
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/mnogosearch

post-install:
	cd ${WRKSRC} && ${TAR} --create --file - --exclude CVS create | (cd ${PREFIX}/share/mnogosearch && ${TAR} xf -)
	${CHMOD} 700 /var/mnogosearch/cache
	${CHOWN} -R www:www /var/mnogosearch/
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/mnogosearch
	${INSTALL_DATA} ${FILESDIR}/spelld.sh-dist ${PREFIX}/etc/rc.d/
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
