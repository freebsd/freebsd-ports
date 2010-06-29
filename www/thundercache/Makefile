# New ports collection makefile for:	thundercache
# Date created:		2010-03-15
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	thundercache
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.bmsoftware.org/freebsd/ \
		http://www8.freebsdbrasil.com.br/~eksffa/thunder/ \
		http://www6.freebsdbrasil.com.br/~eksffa/l/dev/thunder/ \
		${MASTER_SITE_LOCAL}/jmelo
DISTNAME=	thundercache-4.1.201006231050-32bits-fbsd

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	High-performance and high-eficiency caching proxy system

OPTIONS=	DEPENDACK "I have read and understood the depends needs" on \
		APACHE "Install apache for reporting viewing" on \
		PHP "Install PHP for reporting generating" on \
		PGSQL "Install PostgreSQL (report data storing)" on

USE_OPENSSL=	yes
USE_BZIP2=	yes

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	thundercache

NO_BUILD=	yes
LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_TEXT=	Commercial software with shareware license to 50 threads
RESTRICTED=	Commercial software with shareware license to 50 threads

MANUAL_PACKAGE_BUILD=	This port wants PGSQL 8.4, but 8.2 is default and used to build php5-pgsql dependency.

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		Won't run on systems version < FreeBSD 8.0-RELEASE
.endif

.if ${ARCH} == "amd64"
DISTNAME=	thundercache-4.1.201006231050-64bits-fbsd
.endif

WRKSRC=		${WRKDIR}/thunder

.if defined (WITH_APACHE)
USE_APACHE=	2.0+
.endif

.if defined (WITH_PGSQL)
USE_PGSQL=	yes
WANT_PGSQL_VER=	84
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
.endif

.if defined(WITH_PHP) && defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pgsql.so:${PORTSDIR}/databases/php5-pgsql
.endif

.if defined(WITH_PHP)
USE_PHP+=	curl pcre bcmath pdo mcrypt mhash session
.endif

LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl:install

SUB_FILES=	pkg-message log.sh test-deps.sh
SUB_LIST=	"GREP=${GREP}"

show-info:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "ATTENTION:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " It is very important that you carefully read and respect"
	@${ECHO_MSG} " the special build options for the following depends:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " ftp/curl		LIBSSH2=yes OPENSSL=yes PROXY=yes"
	@${ECHO_MSG} " security/openssl	ZLIB=yes"
	@${ECHO_MSG} " devel/php5-pcre	BUNDLED_PCRE=yes (for apache20)"
	@${ECHO_MSG} " postgresql${PGSQL_VER}-server \
					NLS=yes PAM=yes OPTIMIZED_CFLAGS=yes TZDATA=yes"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " After you understood it correctly, select DEPENDACK on"
	@${ECHO_MSG} " the OPTIONS screen. Run ''make config'' to acknowledge"
	@${ECHO_MSG} ""
.if !defined(WITH_DEPENDACK)
	@${FALSE}
.endif

pre-everything::show-info

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/
	${INSTALL_SCRIPT} ${WRKDIR}/log.sh ${PREFIX}/thunder/sbin/
	@${MKDIR} -m 755 /var/run/thunder

post-install:
	@${CAT} ${PKGMESSAGE}
	@(${CHMOD} +x ${WRKDIR}/test-deps.sh ; \
	if ! ${WRKDIR}/test-deps.sh > /dev/null 2>&1 ; then \
		${ECHO_MSG} "**** FATAL **** " ; \
		${ECHO_MSG} "**** THIS PORT MAY NOT WORK PROPERLY **** " ; \
		${ECHO_MSG} "Some depends are not built with required features." ; \
		${ECHO_MSG} "You must always honor at least the following options" ; \
		${ECHO_MSG} "depends as listed:" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "ftp/curl	   LIBSSH2=yes OPENSSL=yes PROXY=yes" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Type ''make show-info'' to read further information." ; \
		${ECHO_MSG} "" ; \
	fi)

.include <bsd.port.post.mk>
