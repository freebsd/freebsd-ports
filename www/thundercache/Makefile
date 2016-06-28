# $FreeBSD$

PORTNAME=	thundercache
PORTVERSION=	6.1
PORTREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://www.thundercache.com.br/dist/ \
		http://www.bmsoftware.org/packs/ \
		http://www8.freebsdbrasil.com.br/~eksffa/thunder/ \
		http://www6.freebsdbrasil.com.br/~eksffa/l/dev/thunder/ \
		LOCAL/jmelo
DISTNAME=	thundercache-6.1.201104260900-${BITS}-fbsd

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	High-performance and high-efficiency caching proxy system

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software with shareware license to 50 threads
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RESTRICTED=	Commercial software with shareware license to 50 threads

OPTIONS_DEFINE=	DEPENDACK APACHE PHP PGSQL
OPTIONS_DEFAULT=DEPENDACK APACHE PHP PGSQL
DEPENDACK_DESC=	I have read and understood the depends needs
APACHE_DESC=	Install apache for reporting viewing
PHP_DESC=	Install PHP for reporting generating
PGSQL_DESC=	Install PostgreSQL (report data storing)

USE_OPENSSL=	yes
USES=		shebangfix tar:bzip2
SHEBANG_FILES=	sbin/thunderlog.php

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	thundercache

NO_BUILD=	yes

.include <bsd.port.options.mk>

BITS=		${ARCH:S/amd64/64/:S/x86_64/64/:S/i386/32/}bits
WRKSRC=		${WRKDIR}/thunder

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
WANT_PGSQL=	server
.endif

.if ${PORT_OPTIONS:MPHP}
USE_PHP+=	curl pcre bcmath pdo mcrypt hash session
.  if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
.  endif
.endif

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libstdc++.so:lang/gcc \
		libutil.so:misc/compat8x

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
.if ! ${PORT_OPTIONS:MDEPENDACK}
	@${FALSE}
.endif

pre-everything::show-info

do-install:
	@${CP} -r ${WRKSRC} ${STAGEDIR}${PREFIX}/
	@${INSTALL_SCRIPT} ${WRKDIR}/log.sh ${STAGEDIR}${PREFIX}/thunder/sbin/
	@${MKDIR} -m 755 ${STAGEDIR}/var/run/thunder

post-install:
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

.include <bsd.port.mk>
