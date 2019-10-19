# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	froxlor
PORTVERSION=	0.9.38.7
PORTREVISION=	4
CATEGORIES=	sysutils www
MASTER_SITES=	http://files.froxlor.org/releases/

MAINTAINER=	coco@executive-computing.de
COMMENT=	PHP-based ISP Server Management Panel

LICENSE=	GPLv2

USES=		php:cli
USE_PHP=	bcmath curl filter ftp json pdo_mysql posix session xml zip

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} PORTNAME=${PORTNAME}
PLIST_SUB=	${SUB_LIST}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	LIBNSS LOGROTATE MYSQLS DKIM PCNTL NLS

OPTIONS_RADIO=	WEB SMTP IMAPPOP3 FTP DNS
OPTIONS_RADIO_WEB=	APACHE LIGHTTPD NGINX
OPTIONS_RADIO_SMTP=	POSTFIX EXIM
OPTIONS_RADIO_IMAPPOP3=	DOVECOT2 COURIER
OPTIONS_RADIO_FTP=	PROFTPD PUREFTPD
OPTIONS_RADIO_DNS=	POWERDNS ISCDNS
OPTIONS_MULTI=	WWWST
OPTIONS_MULTI_WWWST=	WEBALIZER AWSTATS

WWWST_DESC=	Web access and traffic statistics dependency
WEB_DESC=	Web server dependency
SMTP_DESC=	SMTP server dependency
IMAPPOP3_DESC=	IMAP/POP3 server dependency
DNS_DESC=	DNS server dependency
FTP_DESC=	FTP server dependency
APACHE_DESC=	Apache as HTTP/HTTPS server
LIGHTTPD_DESC=	Lighttpd as HTTP/HTTPS server
NGINX_DESC=	Nginx as HTTP/HTTPS server
POSTFIX_DESC=	Postfix as SMTP server
EXIM_DESC=	Exim as SMTP server
DKIM_DESC=	OpenDKIM for DomainKeys Identified Mail
DOVECOT2_DESC=	Dovecot 2.x as IMAP/POP3 server
COURIER_DESC=	Courier as IMAP/POP3 server
PROFTPD_DESC=	ProFTPd as FTP server
PUREFTPD_DESC=	Pure-FTPd as FTP server
POWERDNS_DESC=	Powerdns as DNS server
ISCDNS_DESC=	ISC BIND 9.11 from ports as DNS server
PCNTL_DESC=	Use php-pcntl (speeds up statistics creation)
LIBNSS_DESC=	Libnss-mysql for authentication
WEBALIZER_DESC=	Webalizer (small, fast, static result pages)
AWSTATS_DESC=	Awstats (more fancy, dynamic and static result pages)
LOGROTATE_DESC=	Logrotate for log rotation
MYSQLS_DESC=	Depend on MySQL server
NLS_DESC=	Enable NLS support (required for webFTP frontend)

OPTIONS_DEFAULT=	APACHE POSTFIX DOVECOT2 PROFTPD WEBALIZER MYSQLS PCNTL

POSTFIX_RUN_DEPENDS=	postfix:mail/postfix

EXIM_RUN_DEPENDS=	exim:mail/exim

DKIM_RUN_DEPENDS=	opendkim:mail/opendkim

DOVECOT2_RUN_DEPENDS=	dovecot>=2:mail/dovecot

COURIER_RUN_DEPENDS=	courier:mail/courier

PROFTPD_RUN_DEPENDS=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:databases/proftpd-mod_sql_mysql

PUREFTPD_RUN_DEPENDS=	pure-ftpd:ftp/pure-ftpd

POWERDNS_RUN_DEPENDS=	pdns_control:dns/powerdns

ISCDNS_RUN_DEPENDS=	bind>=9.11.0.0:dns/bind911

LIBNSS_RUN_DEPENDS=	${LOCALBASE}/lib/nss_mysql.so:net/libnss-mysql

WEBALIZER_RUN_DEPENDS=	webalizer:www/webalizer

AWSTATS_RUN_DEPENDS=	awstats>=6.8:www/awstats

LOGROTATE_RUN_DEPENDS=	logrotate:sysutils/logrotate

LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

NGINX_RUN_DEPENDS=	nginx:www/nginx

APACHE_USES=	apache php:mod

MYSQLS_USES=	mysql:server

PCNTL_USE=	PHP=pcntl

NLS_USES=	gettext-runtime:run
NLS_USE=	PHP=gettext

do-install:
	cd ${WRKSRC}/${PORTNAME} && \
	${FIND} . ! -name .gitignore | \
	${CPIO} --quiet -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
