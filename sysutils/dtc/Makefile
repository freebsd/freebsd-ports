# Ports collection makefile for:        dtc
# Date created:                 1 December 2003
# Whom:                         Frederic Cambus & Thomas Goirand
#
# $FreeBSD$
#

PORTNAME=	dtc
PORTVERSION=	0.17.0.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gplhost.com/pub/dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A hosting web GUI for admin and accounting all hosting services

RUN_DEPENDS=	${LOCALBASE}/share/pear/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC \
		proftpd-mysql>=0:${PORTSDIR}/ftp/proftpd-mysql \
		${LOCALBASE}/libexec/apache/mod_log_sql.so:${PORTSDIR}/www/mod_log_sql2 \
		${LOCALBASE}/bin/webalizer:${PORTSDIR}/www/webalizer \
		${LOCALBASE}/www/cgi-bin/sbox:${PORTSDIR}/www/sbox-dtc

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre session

.if defined(WITH_PHP5)
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4
USE_PHP+=	bz2 gd mbstring mcrypt mysql mysqli openssl pcre \
		pear session sockets xml zlib
.endif

DTCROOT?=	www/dtc
DTCDIR=		${PREFIX}/${DTCROOT}
PLIST_SUB+=	DTCROOT="${DTCROOT}"

# Now tested and working. In fact, under BSD it's easyer to use Apache2 now.
# If you know what to do so all dependancies are set correctly, please help!
.if defined(WITH_APACHE2)
IGNORE=		with Apache 2 is untested
.endif

SUB_FILES=	dtc-install dtc-deinstall
SUB_LIST+=	QMAIL_DIR="${QMAIL_DIR}"

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-install ${PREFIX}/sbin/dtc-install
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-deinstall ${PREFIX}/sbin/dtc-deinstall
	@${MKDIR} ${DTCDIR}
	@cd ${WRKSRC} ; ${TAR} cfp - . | ${TAR} xfp - -C ${DTCDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
