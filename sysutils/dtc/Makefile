# Created by: Frederic Cambus & Thomas Goirand & Marc G. Fournier
# $FreeBSD$

PORTNAME=	dtc
PORTVERSION=	0.34.2.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gplhost.sg/pub/dtc/bsd/ \
		ftp://qala-sg.apt-proxy.gplhost.sg/pub/dtc/bsd/ \
		ftp://601.apt-proxy.gplhost.com/pub/dtc/bsd/ \
		ftp://seattle.apt-proxy.gplhost.com/pub/dtc/bsd/ \
		ftp://ftp.gplhost.com/pub/dtc/bsd/ \
		ftp://ftp.gplhost.co.uk/pub/dtc/bsd/ \
		ftp://ftp.gplhost.fr/pub/dtc/bsd/ \
		ftp://972.apt-proxy.gplhost.com/pub/dtc/bsd/ \
		http://ftp.gplhost.fr/pub/dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A hosting web GUI for admin and accounting all hosting services

DEPRECATED=	Depends on expired www/sbox-dtc
EXPIRATION_DATE=2014-04-10

RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_log_sql.so:${PORTSDIR}/www/mod_log_sql2-dtc \
		${LOCALBASE}/share/pear/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC \
		${LOCALBASE}/share/pear/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer \
		${LOCALBASE}/share/pear/Net/IPv4.php:${PORTSDIR}/net/pear-Net_IPv4 \
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
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		${LOCALBASE}/sbin/logrotate:${PORTSDIR}/sysutils/logrotate \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

CONFLICTS=	dtc-toaster-[0-9]* dtc-postfix-courier-[0-9]*

USES=		gettext

USE_GMAKE=	yes

USE_MYSQL=	server

NO_BUILD=	yes
USE_PHP=	mysql pcre session
MAN8=		dtc-chroot-shell.8 dtc-chroot-wrapper.8
MANCOMPRESSED=	no
USE_APACHE_RUN=	22+

.if defined(WITH_PHP5)
DEFAULT_PHP_VER=5
RUN_DEPENDS+=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
USE_PHP+=	bz2 gd mbstring mcrypt mysql mysqli openssl pcre \
		session sockets xml zlib curl
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
RUN_DEPENDS+=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:${PORTSDIR}/databases/proftpd-mod_sql_mysql
.endif

.if defined(WITH_POSTFIX)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.endif
.if defined(WITH_CYRUS_IMAPD)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd23
.elif defined(WITH_COURIER_IMAP)
RUN_DEPENDS+=	${LOCALBASE}/sbin/pop3login:${PORTSDIR}/mail/courier-imap \
		${LOCALBASE}/lib/courier-authlib/libauthmysql.a:${PORTSDIR}/databases/courier-authlib-mysql
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS+=	${LOCALBASE}/bin/maildrop:${PORTSDIR}/mail/maildrop
.endif

.if defined(WITH_CYRUS_SASL2)
RUN_DEPENDS+=	${LOCALBASE}/lib/sasl2/libcrammd5.so:${PORTSDIR}/security/cyrus-sasl2
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	${LOCALBASE}/bin/spamd:${PORTSDIR}/mail/spamassassin
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
RUN_DEPENDS+=	${LOCALBASE}/www/phpMyAdmin/index.php:${PORTSDIR}/databases/phpmyadmin
.endif

.if defined(WITH_DOVECOT)
RUN_DEPENDS+=	${LOCALBASE}/sbin/dovecot:${PORTSDIR}/mail/dovecot
.endif

.if defined(WITH_FREERADIUS)
RUN_DEPENDS+=	${LOCALBASE}/sbin/radiusd:${PORTSDIR}/net/freeradius2
.endif

SUB_FILES=	dtc-install dtc-deinstall
SUB_LIST+=	QMAIL_DIR="${QMAIL_DIR}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-install ${PREFIX}/sbin/dtc-install
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-deinstall ${PREFIX}/sbin/dtc-deinstall
	@${GMAKE} -C ${WRKSRC} install-dtc-common INSTALL=install \
		DTC_APP_DIR=${WWWDIR} DTC_GEN_DIR=${PREFIX}/var/dtc CONFIG_DIR=${PREFIX}/etc DTC_ETC_DIRECTORY=${ETCDIR} \
		DTC_DOC_DIR=${DOCSDIR} MANUAL_DIR=${MANPREFIX}/man BIN_DIR=${PREFIX}/bin UNIX_TYPE=bsd VERS=0.34.2.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
