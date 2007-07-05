# Ports collection makefile for:        dtc
# Date created:                 1 December 2003
# Whom:                         Frederic Cambus & Thomas Goirand
#
# $FreeBSD$
#

PORTNAME=	dtc
PORTVERSION=	0.24.6.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gplhost.com/pub/dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A hosting web GUI for admin and accounting all hosting services

RUN_DEPENDS=	${LOCALBASE}/share/pear/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC \
		${LOCALBASE}/libexec/apache22/mod_log_sql.so:${PORTSDIR}/www/mod_log_sql2-dtc \
		${LOCALBASE}/www/cgi-bin/sbox:${PORTSDIR}/www/sbox-dtc \
		${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo \
		${LOCALBASE}/bin/run-mailcap:${PORTSDIR}/misc/mime-support \
		${LOCALBASE}/lib/nss_mysql.so:${PORTSDIR}/net/libnss-mysql \
		${LOCALBASE}/sbin/chrootuid:${PORTSDIR}/security/chrootuid \
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${X11BASE}/lib/X11/fonts/webfonts/verdana.ttf:${PORTSDIR}/x11-fonts/webfonts \
		${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql50-server

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

NO_BUILD=	yes
USE_PHP=	mysql pcre session

.if defined(WITH_PHP5)
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4
RUN_DEPENDS+=    ${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
USE_PHP+=	bz2 gd mbstring mcrypt mysql mysqli openssl pcre \
		session sockets xml zlib
.endif

.if defined(WITH_WEBALIZER)
RUN_DEPENDS+=	${LOCALBASE}/bin/webalizer:${PORTSDIR}/www/webalizer
.endif

.if defined(WITH_AWSTATS)
RUN_DEPENDS+=	${LOCALBASE}/www/awstats:${PORTSDIR}/www/awstats
.endif

.if defined(WITH_MHONARC)
RUN_DEPENDS+=	${LOCALBASE}/bin/mhonarc:${PORTSDIR}/www/mhonarc
.endif

.if defined(WITH_MLMMJ)
RUN_DEPENDS+=	${LOCALBASE}/bin/mlmmj-list:${PORTSDIR}/mail/mlmmj
.endif

.if defined(WITH_PUREFTPD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/pure-ftpd:${PORTSDIR}/ftp/pure-ftpd
.elif defined(WITH_PROFTPD)
RUN_DEPENDS+=	proftpd-mysql>=0:${PORTSDIR}/ftp/proftpd-mysql
.endif

.if defined(WITH_POSTFIX)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.if defined(WITH_CYRUS_IMAPD)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd23
.endif
.elif defined(WITH_COURIER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/courier/courierd:${PORTSDIR}/mail/courier \
		${LOCALBASE}/lib/pam_mysql.so:${PORTSDIR}/security/pam-mysql
.endif

.if defined(WITH_APACHE2)
USE_APACHE=	2.2+
.endif

DTCROOT?=	www/dtc
DTCDIR=		${PREFIX}/${DTCROOT}
PLIST_SUB+=	DTCROOT="${DTCROOT}"

SUB_FILES=	dtc-install dtc-deinstall
SUB_LIST+=	QMAIL_DIR="${QMAIL_DIR}"

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-install ${PREFIX}/sbin/dtc-install
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-deinstall ${PREFIX}/sbin/dtc-deinstall
	@${MKDIR} ${DTCDIR}
	@cd ${WRKSRC} ; ${TAR} cfp - . | ${TAR} xfp - -C ${DTCDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
