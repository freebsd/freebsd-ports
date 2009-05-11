# New ports collection makefile for:    mnogosearch31
# Date created:         27.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mnogosearch31
PORTVERSION=	3.1.21
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/
DISTNAME=	mnogosearch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}

DEPRECATED=	Use www/mnogosearch instead, this version is ancient
EXPIRATION_DATE=	2009-05-20

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_GMAKE=	yes
APACHE_COMPAT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-phrase \
		--enable-shared \
		--sysconfdir=${PREFIX}/etc/mnogosearch \
		--localstatedir=/var/mnogosearch
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"

.if defined(PACKAGE_BUILDING)
# OPTIONS not counted, workaround
WITH_MNOGO_BUILTIN=true
.endif
OPTIONS=        MNOGO_THREADS "Enable pthreads"                   on  \
		MNOGO_SSL     "Enable SSL"                        on  \
		MNOGO_GUESSER "Enable Cyrillic charset guesser"   off \
		MNOGO_PGSQL   "Use PGSQL (mutually exclusive)"    off \
		MNOGO_MSQL    "Use MSQL (mutually exclusive)"     off \
		MNOGO_MYSQL   "Use MySQL (mutually exclusive)"    off \
		MNOGO_BUILTIN "Use built-in (mutually exclusive)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MNOGO_THREADS)
CONFIGURE_ARGS+=	--enable-freebsd-pthreads
CFLAGS+=        ${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
.endif

.if !defined(NO_OPENSSL) && !defined(WITHOUT_MNOGO_SSL)
USE_OPENSSL=    yes
.endif

.ifdef USE_OPENSSL
CONFIGURE_ARGS+= --with-openssl=${OPENSSLBASE}
.endif

# Guesser mode ignores charsets comes from HTTP header or <META> tag
.if defined(WITH_MNOGO_GUESSER)
CONFIGURE_ARGS+= --enable-charset-guesser
.endif

.if defined(WITH_MNOGO_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}

.elif defined(WITH_MNOGO_MSQL)
LIB_DEPENDS=            msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.elif defined(WITH_MNOGO_MYSQL)
LIB_DEPENDS=		mysqlclient:${PORTSDIR}/databases/mysql41-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

.elif defined(WITH_MNOGO_BUILTIN)
CONFIGURE_ARGS+=        --with-built-in

.else
pre-configure:
	@${ECHO}
	@${ECHO} "One of the databases should be choosed."
	@exit 1
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

.include <bsd.port.post.mk>
