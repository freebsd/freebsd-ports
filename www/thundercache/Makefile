# New ports collection makefile for:	thundercache
# Date created:		2010-03-15
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	thundercache
PORTVERSION=	4.0
CATEGORIES=	www
MASTER_SITES=	http://www.bmsoftware.org/freebsd/ \
		http://www6.freebsdbrasil.com.br/~eksffa/l/dev/thunder/ \
		${MASTER_SITE_LOCAL}/jmelo
DISTNAME=	thunder32bits_17032010

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	High-performance and high-eficiency caching proxy system

OPTIONS=	DEPENDACK "I have read and understood the depends needs" off

USE_OPENSSL=	yes
USE_BZIP2=	yes

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
LICENSE=	shareware / commercial
RESTRICTED=	Commercial software with shareware license to 50 threads

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		Won't run on systems version < FreeBSD 8.0-RELEASE
.endif

.if ${ARCH} == "amd64"
DISTNAME=	thunder64bits_17032010
.endif

WRKSRC=		${WRKDIR}/thunder

USE_PHP+=	curl pcre bcmath pdo mcrypt mhash session pgsql
USE_PGSQL=	yes
WANT_PGSQL_VER=	84
USE_APACHE=	2.0+

LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl:install
RUN_DEPENDS+=	sudo:${PORTSDIR}/security/sudo \
		postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql

SUB_FILES=	pkg-message thunder-rcNG log.sh

pre-everything::
.if !defined(WITH_DEPENDACK)
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
	@${FALSE}
.endif

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/
	${INSTALL_SCRIPT} ${WRKDIR}/thunder-rcNG ${PREFIX}/etc/rc.d/thunder
	${INSTALL_SCRIPT} ${WRKDIR}/log.sh ${PREFIX}/thunder/sbin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
