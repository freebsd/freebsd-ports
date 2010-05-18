# Ports collection makefile for:	dtc
# Date created:				1 December 2003
# Whom:					Frederic Cambus & Thomas Goirand & Marc G. Fournier
#
# $FreeBSD$
#

PORTNAME=	dtc
PORTVERSION=	0.28.2.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gplhost.com/pub/dtc/bsd/ \
		ftp://ftp.gplhost.fr/pub/dtc/bsd/ \
		ftp://ftp.gplhost.sg/pub/dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A hosting web GUI for admin and accounting all hosting services

RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql50-server \
		${LOCALBASE}/libexec/apache22/mod_log_sql.so:${PORTSDIR}/www/mod_log_sql2-dtc \
		${LOCALBASE}/share/pear/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC \
		${LOCALBASE}/www/cgi-bin/sbox:${PORTSDIR}/www/sbox-dtc \
		${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo \
		${LOCALBASE}/lib/nss_mysql.so:${PORTSDIR}/net/libnss-mysql \
		${LOCALBASE}/sbin/chrootuid:${PORTSDIR}/security/chrootuid \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget \
		${LOCALBASE}/share/fpdf/fpdf.php:${PORTSDIR}/print/fpdf \
		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${LOCALBASE}/lib/X11/fonts/webfonts/verdana.ttf:${PORTSDIR}/x11-fonts/webfonts \
		${LOCALBASE}/bin/mhonarc:${PORTSDIR}/www/mhonarc \
		${LOCALBASE}/bin/mlmmj-list:${PORTSDIR}/mail/mlmmj \
		${LOCALBASE}/bin/ncftpput:${PORTSDIR}/ftp/ncftp3 \
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool

NO_BUILD=	yes
USE_PHP=	mysql pcre session

BROKEN=		bad plist
DEPRECATED=	has been broken for 17 months
EXPIRATION_DATE=2010-01-08

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

.if defined(WITH_VISITORS)
RUN_DEPENDS+=	${LOCALBASE}/bin/visitors:${PORTSDIR}/www/visitors
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
.elif defined(WITH_COURIER_IMAP)
RUN_DEPENDS+=	${LOCALBASE}/sbin/pop3login:${PORTSDIR}/mail/courier-imap \
		${LOCALBASE}lib/courier-authlib/libauthmysql.a:${PORTSDIR}/databases/courier-authlib-mysql
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS+=  ${LOCALBASE}/bin/maildrop:${PORTSDIR}/mail/maildrop
.endif

.if defined(WITH_CYRUS_SASL2)
RUN_DEPENDS+=	${LOCALBASE}/lib/sasl2/libcrammd5.so:${PORTSDIR}/security/cyrus-sasl2
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	${LOCALBASE}/bin/spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(WITH_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
.endif

.if defined(WITH_AMAVIS)
RUN_DEPENDS+=	${LOCALBASE}/sbin/amavisd:${PORTSDIR}/security/amavisd-new
.endif

.if defined(WITH_SQUIRRELMAIL)
RUN_DEPENDS+=	${LOCALBASE}/www/squirrelmail/src/login.php:${PORTSDIR}/mail/squirrelmail
.endif

.if defined(WITH_PHPMYADMIN)
RUN_DEPENDS+=	${LOCALBASE}/www/phpMyAdmin/index.html:${PORTSDIR}/databases/phpmyadmin
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
	@${MAKE} -C ${WRKDIR}/dtc-0.28.2.1 install-dtc-common INSTALL=install DTC_APP_DIR=${LOCALBASE}/www DTC_GEN_DIR=${LOCALBASE}/var CONFIG_DIR=${LOCALBASE}/etc \
		DTC_DOC_DIR=${LOCALBASE}/share/doc MANUAL_DIR=${LOCALBASE}/man BIN_DIR=${LOCALBASE}/bin UNIX_TYPE=bsd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
